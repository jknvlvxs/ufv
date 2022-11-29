/*
README
Fontes de consulta:
Pessoas com as quais discuti sobre este exercício:
*/
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class UnionFind {
  private:
    vector<int> representante;

  public:
    void createSet(int tam) {
        representante.resize(tam);
        for (int i = 0; i < tam; i++)
            representante[i] = i;
    }

    // Retorna o representante do conjunto que contem
    // o elemento "elemento"
    int findSet(int elemento) {
        if (representante[elemento] == elemento)
            return elemento;
        // Compressao do caminho...
        representante[elemento] = findSet(representante[elemento]);
        return representante[elemento];
    }

    void mergeSets(int i, int j) {
        representante[findSet(i)] = findSet(j);
    }

    bool isSameSet(int i, int j) {
        return (findSet(i) == findSet(j));
    }
};

struct Edge {
    int v, w, peso;
    Edge(int v = -1, int w = -1, int peso = 0) : v(v), w(w), peso(peso) {}
};

bool operator<(const Edge &i, const Edge &j) {
    return i.peso < j.peso;
}

int kruskal(vector<Edge> &arestas, vector<bool> &arestasUtilizadas, int numVerticesGrafo) {
    arestasUtilizadas = vector<bool>(arestas.size(), false);
    sort(arestas.begin(), arestas.end());

    UnionFind conjuntos;
    conjuntos.createSet(numVerticesGrafo);

    int sz = arestas.size();
    int tamArvore = numVerticesGrafo - 1;
    int ctArestas = 0;

    for (int i = 0; i < sz; i++) {
        if (!conjuntos.isSameSet(arestas[i].v, arestas[i].w)) {
            arestasUtilizadas[i] = true;
            ctArestas++;

            if (ctArestas == tamArvore)
                return ctArestas;

            conjuntos.mergeSets(arestas[i].v, arestas[i].w);
        }
    }
    return ctArestas;
}

int voltas(int n, int m) {
    int num_voltas = 0, diff = 0;

    // primeiro digito
    int origin_d1 = n / 1000;
    int dest_d1 = m / 1000;
    diff = abs(origin_d1 - dest_d1);
    num_voltas += min(diff, 10 - diff);

    // segundo digito
    int origin_d2 = (n % 1000) / 100;
    int dest_d2 = (m % 1000) / 100;
    diff = abs(origin_d2 - dest_d2);
    num_voltas += min(diff, 10 - diff);

    // terceiro digito
    int origin_d3 = (n % 100) / 10;
    int dest_d3 = (m % 100) / 10;
    diff = abs(origin_d3 - dest_d3);
    num_voltas += min(diff, 10 - diff);

    // quarto digito
    int origin_d4 = n % 10;
    int dest_d4 = m % 10;
    diff = abs(origin_d4 - dest_d4);
    num_voltas += min(diff, 10 - diff);

    return num_voltas;
}

int main() {
    int test_cases;
    cin >> test_cases;

    for (int t = 0; t < test_cases; t++) {
        int n; // numero de chaves
        cin >> n;

        vector<int> chaves(n + 1);

        chaves[0] = 0;

        for (int i = 1; i <= n; i++)
            cin >> chaves[i];

        vector<Edge> arestas;
        for (int i = 0; i <= n; i++)
            for (int j = 0; j < i; j++) {
                if (i != j) {
                    arestas.push_back(Edge(i, j, voltas(chaves[i], chaves[j])));
                    // printf("Distancia de %d para %d: %d\n", chaves[j], chaves[i], voltas(chaves[i], chaves[j]));
                }
            }

        // print arestas
        for (int i = 0; i < arestas.size(); i++)
            printf("Aresta %d: %d %d %d\n", i, arestas[i].v, arestas[i].w, arestas[i].peso);

        vector<bool> arestasUtilizadas;
        kruskal(arestas, arestasUtilizadas, n + 1);

        int custoMinimo = 0;

        // vector<int> listaIdsArestasUtilizadas;
        for (int i = 0; i < arestas.size(); i++) {
            if (arestasUtilizadas[i]) {
                printf("Aresta %d: %d %d %d\n", i, arestas[i].v, arestas[i].w, arestas[i].peso);
                // listaIdsArestasUtilizadas.push_back(i);
                custoMinimo += arestas[i].peso;
            }
        }

        printf("Custo minimo: %d\n\n", custoMinimo);
    }

    return 0;
}
