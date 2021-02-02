#include <iostream>
#include <ctype.h>
#include <stdlib.h>
#include <time.h> 
#include <stdio.h>
#include <string.h>

using namespace std;

struct Signo {
    char nome[12];
    int diaInicio, mesInicio, diaFim, mesFim;
    char descricao[1000];
};

struct Mes {
    char nome[12];
    int nDias;
};

// função pra receber char com nome do signo e informar o valor do signo no vetor de Signo
void verificarSigno(char signo[], Signo signos[], int &valorSigno){
    for(int i = 0; i < 12; i++){
        if(strcmp(signos[i].nome, signo) == 0){
            valorSigno = i;
            break;
        }
    }
}

// função pra receber char com nome do mes e informar o valor do mes no vetor de Mes
void verificarMes(char mes[], Mes meses[], int &valorMes){
    for(int i = 0; i < 12; i++){
        if(strcmp(meses[i].nome, mes) == 0){
            valorMes = i;
            break;
        }
    }
}

// função para buscar o valor do signo conforme a dia e mes informados
void buscarSigno(int dia, int mes, Signo signos[], int &valorSigno){
    for(int i = 0; i < 12; i++){
        if(dia >= signos[i].diaInicio && mes == signos[i].mesInicio || dia <= signos[i].diaFim && mes == signos[i].mesFim){
            valorSigno = i;
        }
    }
}

// função para formatar a entrada de char como nome, mes e signo
void formatarEntrada(char leitura[], char formatada[], int &j) {
    for(int i = 0; leitura[i] != '\0'; i++){
        formatada[j] = leitura[i];
        if(formatada[j] == ' ') j = 0; 
        else j++;
    }
    formatada[j] = '\0'; j = 0;

    formatada[0] = toupper(formatada[0]);
    for (int i = 1; i < strlen(formatada); i++)
        formatada[i] = tolower(formatada[i]);
}

int main () {
    Signo signos[12] = {
        {"Aries", 21, 3, 19, 4, "Aries e o signo dos nascidos entre 21 de marco a 19 de abril. E um signo regido por Marte. Tem o fogo como elemento. As pessoas do signo de Aries costumam ser muito alegres, extrovertidas e cheias de energia. Porem, tambem abre portas para possiveis explosoes emocionais, o que faz muitos acreditarem, injustamente, que aries e um 'signo ruim'. Alguns famosos do signo de Aries sao Quentin Tarantino, Robert Downey Jr, Anitta, Pedro Bial e Ana Maria Braga"},
        {"Touro", 20, 4, 20, 5, "Touro e o signo dos nascidos entre 20 de abril a 20 de maio. E um signo regido por Venus. Tem a terra como elemento. Pessoas do signo de Touro costumam ser calmas, pacientes, amorosas e sensuais. Gostam de conforto, prazer e seguranca em tudo que fazem e tem gosto por coisas concretas. Em contrapartida, Touro odeia desperdicios, situacoes arriscadas e mudancas repentinas, o que ressalta uma tendencia a possessividade e teimosia excessiva. Alguns famosos do signo de Touro sao Rainha Elizabeth II, Rodrigo Hilbert, Channing Tatum, David Beckham, Henry Cavill, Megan Fox e Mark Zuckerberg."},
        {"Gemeos", 21, 5, 21, 6, "Gemeos e o signo dos nascidos entre 21 de maio a 21 de junho. E um signo regido por Mercurio. Tem o ar como elemento. Pessoas do signo de Gemeos costumam ser curiosas, inteligentes e versateis. Fazem novas amizades com muita facilidade, pois adoram puxar uma conversa, e conseguem se adaptar a diversas formas de pensamento por conta de seu alto poder de comunicacao. Por outro lado, tendem a odiar rotinas macantes e exaustivas que as impecam de exercer sua criatividade e curiosidade, ou seja, nao gostam de pessoas, lugares e situacoes tediosas. Alguns famosos do signo de Gemeos sao Angelina Jolie, Nicole Kidman, Chris Evans, Morgan Freeman, Camila Pitanga e Sir Paul McCartney."},
        {"Cancer", 22, 6, 20, 7, "Cancer e o signo dos nascidos entre 22 de junho a 20 de julho. E um signo regido pela Lua. Tem a agua como elemento. Emotivas e sensiveis, pessoas do signo de cancer costumam ser guiadas por seus sentimentos. Acredita-se que seu simbolo e o caranguejo por conta da sua carapaca que simboliza seu desejo de seguranca e suas patas em formato de pinca que representam sua tendencia ao apego. Um dos motivos do signo de cancer ter a fama de sofrer ou chorar muito pode ser por conta de seu regente: a Lua, que e o astro responsavel pelas questoes emocionais. Alguns famosos do signo de Cancer sao Meryl Streep, Marina Ruy Barbosa, Gisele Bündchen e Selena Gomez."},
        {"Leao", 23, 7, 22, 8, "Leao e o signo dos nascidos entre 23 de julho a 22 de agosto. E um signo regido pelo Sol. Tem o fogo como elemento. Pessoas do signo de Leao costumam ser muito confiantes e seguras e assim como o felino leao, seu simbolo. Donos de uma nobreza natural e enorme coragem criatividade, leoninos e leoninas gostam de brilhar assim como o seu astro regente, o Sol. Entretanto, quem e do signo de leao nao gosta muito de pedir desculpas, tambem pode desenvolver excesso de orgulho e disposicao para dramatizar seus sentimentos. Alguns famosos do signo de Leao sao Dua Lipa, Bruna Marquezine, Shawn Mendes, Sandra Bullock, Rodrigo Santoro e Madonna."},
        {"Virgem", 23, 8, 22, 9, "Virgem e o signo dos nascidos entre 23 de agosto a 22 de setembro. E um signo regido por Mercurio. Tem a terra como elemento. O signo de Virgem e regido pelo planeta Mercurio e seus nativos costumam ser objetivos, organizados e praticos. Gostam de se sentir uteis e produtivos, buscando melhorar a cada dia em todas as as suas tarefas, sempre dando o seu melhor. Por viverem em busca da perfeicao, pessoas do signo de virgem acabam se cobrando de maneira excessiva, o que pode leva-las a serem detalhistas compulsivas. Alguns famosos do signo de Virgem sao Zendaya, Beyonce, Niall Horan, Principe Harry e Nick Jonas."},
        {"Libra", 23, 9, 22, 10, "Libra e o signo dos nascidos entre 23 de setembro a 22 de outubro. E um signo regido por Venus. Tem o ar como elemento. Pessoas do signo de Libra sao gentis, diplomaticas e vivem na busca constante do equilibrio. Libra significa balanca, reforcando o perfil dos nativos deste signo de representantes da justica. Tambem amam festas e gostam muito de luxo, beleza e bom gosto. O que o signo de libra nao gosta e conflito, esses nativos fazem o possivel e o impossivel pela paz e conciliacao. Tambem podem ter dificuldades de tomar decisoes. Alguns famosos do signo de Libra sao Will Smith, Kim Kardashian, Zac Efron, Ryan Reynolds e Donald Glover."},
        {"Escorpiao", 23, 10, 21, 11, "Escorpiao e o signo dos nascidos entre 23 de outubro a 21 de novembro. E um signo regido por Marte e Plutao. Tem a agua como elemento. Pessoas do signo de Escorpiao costumam ser intensas, passionais e com enorme poder transformador. Possuem um espirito de detetive e otimo sexto sentido, gostam de ver o que nao e mostrado, ouvir o que nao e dito e ler o que nao esta escrito. Quem tem escorpiao forte no mapa costuma ter uma memoria muito boa, nao esquecem o que lhe fazem, seja bom ou ruim. Por isso, levam a fama de vingativos e ancorosos. Alguns famosos do signo de Escorpiao sao Katy Perry, Leonardo DiCaprio, Emma Stone, Julia Roberts e Drake."},
        {"Sagitario", 22, 11, 21, 12, "Sagitario e o signo dos nascidos entre 22 de novembro a 21 de dezembro. E um signo regido por Jupiter. Tem o fogo como elemento. Pessoas do signo de sagitario costumam ser otimistas, joviais e aventureiras. Considerado o signo mais positivo de todos, sagitario possui Jupiter como regente e o centauro como simbolo, representando sua busca por conhecimento e os estagios da evolucao humana. Por suas qualidades comunicativas e espontaneas, nativos de sagitarios odeiam se sentir sozinhos. Os nativos de sagitario so precisam tomar cuidado com a vaidade, pois tendem a se achar autoridades em assuntos que nao dominam tanto, gostam de parecer 'os donos da verdade'. Alguns famosos do signo de Sagitario sao Brad Pitt, Jay-Z, Scarlett Johansson e Britney Spears."},
        {"Capricornio", 22, 3, 19, 1, "Capricornio e o signo dos nascidos entre 22 de dezembro a 19 de janeiro. E um signo regido por Saturno. Tem a terra como elemento. Nativos de Capricornio costumam ser responsaveis, competentes e desde muito cedo, aprendem que tudo na vida demanda tempo e dedicacao. Gostam de ser independentes e criar seus proprios caminhos, nao gostam muito de seguir rotas tracadas por outros. Para Capricornio, dinheiro e liberdade. Porem, o excesso de foco material pode contribuir para o desenvolvimento de posturas avarentas ou excessivamente ambiciosas. Alguns famosos do signo de Capricornio sao Michelle Obama, Jude Law, Jim Carrey, Mel Gibson, Jared Leto e Marilyn Manson."},
        {"Aquario", 20, 1, 18, 2, "Aquario e o signo dos nascidos entre 21 de janeiro a 19 de fevereiro. E um signo regido por Saturno e Urano. Tem o ar como elemento. Nativos do signo de aquario costuma ser inovadores, idealistas e revolucionarios. Seu significado ja diz tudo: o aquario recebe a energia criadora que, ao ser despejada, alimenta o mundo com sabedoria que ultrapassa o conhecimento comum. Porem, pessoas do signo de aquario podem ser bem imprevisiveis e tem tendencia a ter atitudes consideradas radicais ou 'Do contra'. Alguns famosos do signo de Aquario sao Shakira, Ellen DeGeneres, Chloe Grace Moretz e Jennifer Anniston."},
        {"Peixes", 19, 2, 20, 3, "Peixes e o signo dos nascidos entre 19 de fevereiro a 20 de marco. E um signo regido por Netuno e Jupiter. Tem a agua como elemento e possui maiscompatibilidade com Virgem e Touro. As pessoas do signo de Peixes possui como pontos fortes a compaixao, o lado artistico, a intuicao, a gentileza e a sabedoria. Como pontos fracos a tristeza, a vitimizacao, o desejo de escapar da realidade e omedo. Alguns famosos do signo de Peixes sao Rihanna, Drew Barrymore, Regina Case, Justin Bieber, Sharon Stone, Albert Einstein, Michelangelo e Daniel Craig."},
    };

    Mes meses[12] = {
        {"Janeiro", 31},
        {"Fevereiro", 29},
        {"Marco", 31},
        {"Abril", 30},
        {"Maio", 31},
        {"Junho", 30},
        {"Julho", 31},
        {"Agosto", 31},
        {"Setembro", 30},
        {"Outubro", 31},
        {"Novembro", 30},
        {"Dezembro", 31},
    };

    char apresentacao[2][100] = {
        "Ola, meu nome e Saori. Eu sei falar sobre signos do zodiaco. Qual e o seu nome?",
        "Ola, me chamo Saori. Estou aqui para falar sobre signos do zodiaco. Como voce se chama?"
    };

    char perguntaSigno[2][100] = {
        "Me fale um signo ou um mes do ano.",
        "Favor informar um signo ou mes do ano."
        "Sobre qual signo ou mes voce gostaria de saber?"
    };

    char erroLeitura[3][100] = {
        "Desculpe, nao entendi o que voce quis dizer. ",
        "Estou confusa, nao consegui entender o que voce disse. ",
        "Perdao, nao compreendi sua resposta. "
    };

    char despedida[3][20] = {
        "Ate logo!",
        "Tchau!",
        "Ate mais!"
    };

    int j = 0;
    char leituraNome[100], nome[100] = "";
    char leituraLinha[100], leitura[100] = "";
    int valorSigno = -1, valorMes = -1, valorDia = 0; 

    // NOTE 1 - apresentacao do chat bot
    srand (time(NULL));
    cout << "Saori: " << apresentacao[rand()%2] << endl;

    // NOTE 2 - leitura e apresentacao do nome de usuario
    cout << "Usuario: "; cin.getline(leituraNome, 100);
    formatarEntrada(leituraNome, nome, j);
    cout << "Saori: " << "Ola " << nome << ". ";
    
    // NOTE 3 - leitura de mes ou signo, ate a despedida
    while((strcmp (leitura, ("Tchau")) != 0) && (strcmp (leitura, ("Fechar")) != 0) && (strcmp (leitura, ("Sair")) != 0)) {
        srand (time(NULL));
        cout << perguntaSigno[rand()%2] << endl;

        cout << nome << ": ";
        cin.getline(leituraLinha, 100);
        formatarEntrada(leituraLinha, leitura, j);
        
        verificarSigno(leitura, signos, valorSigno);
        verificarMes(leitura, meses, valorMes); 

        if(valorSigno >= 0){
            cout << "Saori: " << signos[valorSigno].descricao << endl;
            cout << "Saori: ";
        } else if(valorMes >= 0) {
            cout << "Saori: ";
            while (valorDia < 1 || valorDia > meses[valorMes].nDias){
                cout << "Me fale um dia do mes de " << meses[valorMes].nome << "." << endl;
                cout << nome << ": "; 
                cin >> valorDia;
                if (cin.fail() || valorDia <= 0) {
                    cin.clear(); 
                    cout << "Saori: O valor informado nao e um numero valido. ";
                    valorDia = 0;
                }
                cin.ignore();
                if(valorDia > meses[valorMes].nDias)
                    cout << "Saori: " << meses[valorMes].nome << " nao possui " << valorDia << " dias. ";
            }
            buscarSigno(valorDia, valorMes+1, signos, valorSigno);
            cout << "Saori: " << signos[valorSigno].descricao << endl;
            cout << "Saori: ";
        } else if((strcmp (leitura, ("Tchau")) != 0) && (strcmp (leitura, ("Fechar")) != 0) && (strcmp (leitura, ("Sair")) != 0)){
            srand (time(NULL));
            cout << "Saori: " << erroLeitura[rand()%3];
        }
        valorSigno = -1;
        valorMes = -1;
        valorDia = 0;
    }

    // NOTE 4 - Exibir despedida do bot
    srand (time(NULL));
    cout << despedida[rand()%3];

    return 0;
}