// Objeto com referências aos itens de acesso direto
const objetos = {
    // Atributos
    insercao: document.getElementById('insercao'),
    edicao: document.getElementById('edicao'),
    pendentes: document.getElementById('pendentes'),
    concluidas: document.getElementById('concluidas'),
    inputNova: document.getElementById('nova'),
    inputEdita: document.getElementById('edita'),
    pesquisa: document.getElementById('pesquisa'),
    filtro: document.getElementById('filtro'),
    ferramentas: document.getElementById('ferramentas'),
    btnCancela: document.getElementById('btnCancelar'),
    btnAtualiza: document.getElementById('btnAtualizar'),
    btnIns: document.getElementById('btnInserir'),
    btnApaga: document.getElementById('apaga'),
    reset: document.getElementById('reset'),
    tarefaArrastada: null,
    buffer: null,

    // Métodos
    ocultar: (item) => {
        this[item].classList.add('oculto');
    },

    mostrar: (item) => {
        this[item].classList.remove('oculto');
    }
};

function pendente(el) {
    return el.parentNode == objetos.pendentes;
}

function defineConcluida(el) {
    Array.from(el.children).forEach(
        function(filho) {
            filho.classList.add('concluida');
        }
    );
}

function definePendente(el) {
    Array.from(el.children).forEach(
        function(filho) {
            filho.classList.remove('concluida');
        }
    );
}

function inverteEstado(el) {
    if (pendente(el)) {
        defineConcluida(el);
    } else {
        definePendente(el);
    }
}

function concluir() {
    let el = this.parentNode;
    let direcao = (pendente(el))?1:2;
    inverteEstado(el);
    if (direcao == 1) {
        objetos.pendentes.removeChild(el);
        objetos.concluidas.appendChild(el);
    } else {
        objetos.concluidas.removeChild(el);
        objetos.pendentes.appendChild(el);
    }
}

function editar() {
    objetos.ocultar('insercao');
    objetos.ocultar('pendentes');
    objetos.ocultar('concluidas');
    objetos.ocultar('ferramentas');
    
    objetos.mostrar('edicao');

    let li = this.parentNode;
    objetos.buffer = li;
    let texto = li.querySelector('span').innerText;

    objetos.inputEdita.value = texto;
}

function remover() {
    let li = this.parentNode;
    let texto = li.querySelector('span').innerText;

    const resp = window.confirm('Tem certeza que deseja excluir a tarefa ' + texto + '?');

    if (resp) {
        let lista = li.parentNode;
        lista.removeChild(li);
    }
}

function criaTarefa(texto, concluida=false) {
    let li = document.createElement('li');

    let sp = document.createElement('span');

    let spTxt = document.createTextNode(texto);
    sp.appendChild(spTxt);

    let btnConc = document.createElement('button');
    let btnEdit = document.createElement('button');
    let btnDel = document.createElement('button');

    btnConc.innerHTML = '&#10003;';
    btnEdit.innerHTML = '&#128395;';
    btnDel.innerHTML = '&#128465;';
    
    sp.classList.add('tarefa');

    btnConc.classList.add('concluir');
    btnConc.addEventListener('click', concluir);

    btnEdit.classList.add('editar');
    btnEdit.addEventListener('click', editar);
    
    btnDel.classList.add('remover');
    btnDel.addEventListener('click', remover);

    if (concluida) {
        sp.classList.add('concluida');
        btnConc.classList.add('concluida');
        btnEdit.classList.add('concluida');
        btnDel.classList.add('concluida');
    }

    li.appendChild(sp);
    li.appendChild(document.createTextNode(' '));
    li.appendChild(btnConc);
    li.appendChild(document.createTextNode(' '));
    li.appendChild(btnEdit);
    li.appendChild(document.createTextNode(' '));
    li.appendChild(btnDel);

    li.setAttribute('draggable', true);
    li.addEventListener('dragstart', (event) => {
        objetos.tarefaArrastada = li;
        event.dataTransfer.effectAllowed = 'move';
        let texto = li.querySelector('span').innerText;
        event.dataTransfer.setData('text', texto);
        li.classList.add('dragging');
    });
    
    li.addEventListener('dragend', (event) => {
        objetos.tarefaArrastada = null;
        li.classList.remove('dragging');
    });
    
    return li;
}

function insere() {
    let texto = objetos.inputNova.value;

    if (!texto) {
        alert('Informe um texto para a tarefa');
    } else {
        let li = criaTarefa(texto);
        objetos.pendentes.appendChild(li);
        objetos.inputNova.value = '';
        objetos.inputNova.focus();
    }
}

function atualiza() {
    let texto = objetos.inputEdita.value;

    if (!texto) {
        alert('Informe um texto para a tarefa');
    } else {
        let li = objetos.buffer;
        li.querySelector('span').innerText = texto;

        objetos.mostrar('insercao');
        objetos.mostrar('pendentes');
        objetos.mostrar('concluidas');
        objetos.mostrar('ferramentas');
        
        objetos.inputEdita.value = '';
        objetos.ocultar('edicao');

        if (!pendente(li)) {
            inverteEstado(li);
            objetos.concluidas.removeChild(li);
            objetos.pendentes.appendChild(li);
        }

        objetos.buffer = null;
    }
}

function cancela() {
    objetos.mostrar('insercao');
    objetos.mostrar('pendentes');
    objetos.mostrar('concluidas');
    objetos.mostrar('ferramentas');
    
    objetos.inputEdita.value = '';
    objetos.ocultar('edicao');

    objetos.buffer = null;
}

function busca(evento) {
    let chave = evento.target.value.toLowerCase();
    
    [objetos.pendentes, objetos.concluidas].forEach((lista) => {
            Array.from(lista.children).forEach((filho) => {
                filho.style.display = "flex";
                let texto = filho.querySelector('span').innerText.toLowerCase();
                if (!texto.includes(chave)) {
                    filho.style.display = "none";
                }
            });
        }
    );
}

function limpaBusca() {
    objetos.pesquisa.value = '';
    objetos.pesquisa.dispatchEvent(new Event('keyup'));
}

function filtra() {
    let valor = objetos.filtro.value;

    if (valor == 'todas') {
        objetos.mostrar('pendentes');
        objetos.mostrar('concluidas');
    } else if (valor == 'afazer') {
        objetos.mostrar('pendentes');
        objetos.ocultar('concluidas');
    } else {
        objetos.ocultar('pendentes');
        objetos.mostrar('concluidas');
    }
}

objetos.btnIns.addEventListener('click', insere);
objetos.btnAtualiza.addEventListener('click', atualiza);
objetos.btnCancela.addEventListener('click', cancela);

objetos.pesquisa.addEventListener('keyup', busca);
objetos.btnApaga.addEventListener('click', limpaBusca);
objetos.filtro.addEventListener('change', filtra);


objetos.pendentes.addEventListener('dragover', (event) => {
    event.preventDefault();
    event.dataTransfer.dropEffect = 'move';
    objetos.pendentes.classList.add('dragover');
});

objetos.concluidas.addEventListener('dragover', (event) => {
    event.preventDefault();
    event.dataTransfer.dropEffect = 'move';
    objetos.concluidas.classList.add('dragover');
});

objetos.pendentes.addEventListener('dragleave', () => {
    objetos.pendentes.classList.remove('dragover');
});

objetos.concluidas.addEventListener('dragleave', () => {
    objetos.concluidas.classList.remove('dragover');
});

objetos.pendentes.addEventListener('drop', (event) => {
    event.preventDefault();
    let texto = event.dataTransfer.getData('text');
    let novoItem = criaTarefa(texto, false);
    objetos.pendentes.appendChild(novoItem);
    objetos.tarefaArrastada.parentNode.removeChild(objetos.tarefaArrastada);
    objetos.pendentes.classList.remove('dragover');
});

objetos.concluidas.addEventListener('drop', (event) => {
    event.preventDefault();
    let texto = event.dataTransfer.getData('text');
    let novoItem = criaTarefa(texto, true);
    objetos.concluidas.appendChild(novoItem);
    objetos.tarefaArrastada.parentNode.removeChild(objetos.tarefaArrastada);
    objetos.concluidas.classList.remove('dragover');
});
