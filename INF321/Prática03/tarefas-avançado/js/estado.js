function observarAlteracoes(mutacoes) {
    mutacoes.forEach(function (mutacao) {
        salvaEstado();
    });
}
let observadorPend = new MutationObserver(observarAlteracoes);
let observadorConc = new MutationObserver(observarAlteracoes);
let opcoes = {
    childList: true, // Observar adições/remoções de elementos filhos
    subtree: true,   // Observar todos os descendentes, não apenas os filhos diretos
    attributes: true, // Observar mudanças nos atributos dos elementos (opcional)
    characterData: true, // Observar mudanças no conteúdo de texto dos elementos (opcional)
};

observadorPend.observe(objetos.pendentes, opcoes);
observadorConc.observe(objetos.concluidas, opcoes);

// Para parar de observar, você pode chamar observadorPend.disconnect()
// observadorPend.disconnect();

const salvaEstado = () => {
    let estado = criaEstado();
    localStorage.setItem('estado', JSON.stringify(estado));
};

const recuperaEstado = () => {
    // Se não houver nada no localStorage, cria um objeto vazio
    const estado = JSON.parse(localStorage.getItem('estado')) || {};
    return estado;
};

const criaEstado = () => {
    const estado = {
        filtro: objetos.filtro.value,
        pesquisa: objetos.pesquisa.value,
        itens: []
    }

    Array.from(objetos.pendentes.children).forEach((filho) => {
        let texto = filho.querySelector('span').innerText;
        estado.itens.push([texto, false]);
    });

    Array.from(objetos.concluidas.children).forEach((filho) => {
        let texto = filho.querySelector('span').innerText;
        estado.itens.push([texto, true]);
    });

    return estado;
}

const carregaEstado = () => {
    let estado = recuperaEstado();

    if (Object.keys(estado).length !== 0) {
        estado.itens.forEach((item) => {
            let li = criaTarefa(item[0], concluida=item[1]);
            if (!item[1]) {
                objetos.pendentes.appendChild(li);
            } else {
                objetos.concluidas.appendChild(li);
            }
        });
        
        objetos.filtro.value = estado.filtro;
        objetos.filtro.dispatchEvent(new Event('change'));
        objetos.pesquisa.value = estado.pesquisa;
        objetos.pesquisa.dispatchEvent(new Event('keyup'));
    }
}

const reset = () => {
    const resp = window.confirm('Tem certeza que deseja limpar todo o conteúdo?');

    if (resp) {
        localStorage.removeItem('estado');
        window.location.reload();
    }
}

objetos.reset.addEventListener('click', reset);

carregaEstado();
