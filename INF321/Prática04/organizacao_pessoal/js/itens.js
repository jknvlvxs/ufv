class ItemGerenciavel {
    static urlRegExp = /^(https?|ftp):\/\/[^\s/$.?#].[^\s]*$|^\/[^\s/$.?#][^\s]*$/i;

    constructor(_nome) {
        this.id = this.geraId();
        this.nome = _nome;
        this.elemento = null;
    }

    get nome() {
        return this._nome;
    }

    set nome(stringNome) {
        if (typeof stringNome != 'string') {
            throw new Error('O parâmetro nome precisa ser uma string.');
        }

        this._nome = stringNome;
    }

    geraId() {
        // Gera hexadecimal a partir da hora do computador
        const timestamp = new Date().getTime().toString(16);
        // Gera um acréscimo hexadecimal aleatório
        const rnd = Math.random().toString(16).substring(2,10);

        return timestamp + rnd;
    }
}

class Tag extends ItemGerenciavel {
    constructor(_nome, _texto) {
        // Evocar o construtor da classe mãe
        super(_nome);

        this.texto = _texto;
    }

    get texto() {
        return this._texto;
    }

    set texto(_texto) {
        if (typeof _texto != 'string') {
            throw new Error('O texto da tag necessita ser uma string');
        }

        this._texto = _texto;
    }

    render() {
        this.elemento = document.createElement('span');
        this.elemento.setAttribute('draggable', 'true');
        this.elemento.setAttribute('id', this.id);
        this.elemento.classList.add('tag');

        let texto = document.createTextNode(this.texto);
        this.elemento.appendChild(texto);
    }
}

class Imagem extends ItemGerenciavel {
    static extensoes = ['png', 'jpg', 'jpeg', 'gif', 'webp'];

    constructor (_nome, _url, _alt) {
        super(_nome);

        this.url = _url;
        this.alt = _alt;
        this.elemento = null;
    }

    get url() {
        return this._url;
    }

    set url(_url) {
        // URL precisa ser string
        if (typeof _url != 'string') {
            throw new Error('A url precisa ser uma string');
        }

        // A URL precisa casar com o padrão da expressão regular de URL
        if (!ItemGerenciavel.urlRegExp.test(_url)) {
            throw new Error('A url informada não é válida');
        }

        // A URL precisa representar uma imagem (dentro das permitidas)
        let posPonto = _url.lastIndexOf('.');
        if (posPonto === -1) {
            throw new Error('A url informada não é uma imagem válida');
        }

        let extensao = _url.substring(posPonto+1).toLocaleLowerCase();
        // Verifica se a extensão está na lista de extensões permitidas
        if (!Imagem.extensoes.includes(extensao)) {
            throw new Error('Extensão de arquivo não reconhecida');
        }

        this._url = _url;
    }

    get alt() {
        return this._alt;
    }

    set alt(_alt) {
        if (typeof _alt != 'string') {
            throw new Error('Alt precisa ser uma string');
        }

        this._alt = _alt;
    }

    render() {
        this.elemento = document.createElement('img');
        this.elemento.setAttribute('src', this.url);
        this.elemento.setAttribute('alt', this.alt);
        this.elemento.setAttribute('id', this.id);
    }
}

try {
    const tag = new Tag('Tag1', 'Pessoal');
    const tag2 = new Tag('Tag2', 'Profissional');
    const img = new Imagem('Papagaios', 'http://127.0.0.1:5500/static/papagaios.png', 'Dois papagaios coloridões');
    // Acrescentar a tag na tela
    tag.render(); // Renderizou (gerou o DOM Element)
    tag2.render();
    img.render();
    let corpo = document.querySelector('body'); // Identificou a tag body
    corpo.appendChild(tag.elemento); // Acrescenta na página a nova tag
    corpo.appendChild(tag2.elemento);
    corpo.appendChild(img.elemento);
} catch (erro) {
    console.log(erro.message);
}
