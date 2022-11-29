/*
README
Fontes de consulta:
Pessoas com as quais discuti sobre este exercício:
*/
#include <algorithm>
#include <cmath>
#include <iomanip>
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
    int v, w;
    double peso;
    Edge(int v = -1, int w = -1, double peso = 0) : v(v), w(w), peso(peso) {}
};

bool operator<(const Edge &i, const Edge &j) {
    return i.peso < j.peso;
}

int kruskal(vector<Edge> &arestas, vector<double> &pesosArestasUtilizadas, int numVerticesGrafo) {
    UnionFind conjuntos;
    conjuntos.createSet(numVerticesGrafo);

    int sz = arestas.size();
    int tamArvore = numVerticesGrafo - 1;
    int ctArestas = 0;
    for (int i = 0; i < sz; i++) {
        if (!conjuntos.isSameSet(arestas[i].v, arestas[i].w)) {
            pesosArestasUtilizadas.push_back(arestas[i].peso);
            ctArestas++;

            if (ctArestas == tamArvore)
                return ctArestas;

            conjuntos.mergeSets(arestas[i].v, arestas[i].w);
        }
    }
    return ctArestas;
}

double distancia(pair<int, int> p1, pair<int, int> p2) {
    return sqrt(pow(p1.first - p2.first, 2) + pow(p1.second - p2.second, 2));
}

int main() {

    int casos_de_testes;

    cin >> casos_de_testes;

    for (int n = 0; n < casos_de_testes; n++) {
        int s = 0; // numero de satélites
        int p = 0; // numero de postos avançados

        cin >> s >> p;

        vector<pair<int, int>> coordenadas(p);

        for (int i = 0; i < p; i++) {
            int x, y;
            cin >> x >> y;
            coordenadas[i] = make_pair(x, y);
        }

        vector<Edge> arestas;
        for (int i = 0; i < p; i++)
            for (int j = 0; j < p; j++)
                if (i != j)
                    arestas.push_back(Edge(i, j, distancia(coordenadas[i], coordenadas[j])));

        sort(arestas.begin(), arestas.end());

        vector<double> pesosArestasUtilizadas;
        kruskal(arestas, pesosArestasUtilizadas, p);

        cout << setprecision(2) << fixed << pesosArestasUtilizadas[pesosArestasUtilizadas.size() - s] << endl;
    }

    return 0;
}