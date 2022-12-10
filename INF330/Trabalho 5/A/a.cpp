/*
README
Fontes de consulta: http://shygypsy.com/tools/flow2.cpp
Pessoas com as quais discuti sobre este exercício:
*/
#include <algorithm>
#include <iostream>
#include <sstream>
#include <stdio.h>
#include <string.h>
#include <string>
#include <vector>

using namespace std;

/**
 *   //////////////////
 *   // MAXIMUM FLOW //
 *   //////////////////
 *
 * This file is part of my library of algorithms found here:
 *      http://shygypsy.com/tools/
 * LICENSE:
 *      http://shygypsy.com/tools/LICENSE.html
 * Copyright (c) 2006
 * Contact author:
 *      abednego at gmail.c0m
 **/

/****************
 * Maximum flow * (Dinic's on an adjacency list + matrix)
 ****************
 * Takes a weighted directed graph of edge capacities as an adjacency
 * matrix 'cap' and returns the maximum flow from s to t.
 *
 * PARAMETERS:
 *      - cap (global): adjacency matrix where cap[u][v] is the capacity
 *          of the edge u->v. cap[u][v] is 0 for non-existent edges.
 *      - n: the number of vertices ([0, n-1] are considered as vertices).
 *      - s: source vertex.
 *      - t: sink.
 * RETURNS:
 *      - the flow
 *      - prev contains the minimum cut. If prev[v] == -1, then v is not
 *          reachable from s; otherwise, it is reachable.
 * RUNNING TIME:
 *      - O(n^3)
 * FIELD TESTING:
 *      - Valladolid 10330: Power Transmission (Gives WA, but it's probably my graph building that's wrong)
 *      - Valladolid 563:   Crimewave
 *      - Valladolid 753:   A Plug for UNIX
 *      - Valladolid 10511: Councilling
 *      - Valladolid 820:   Internet Bandwidth
 *      - Valladolid 10779: Collector's Problem
 * #include <string.h>
 **/

// the maximum number of vertices
#define NN 40

// adjacency matrix (fill this up)
// If you fill adj[][] yourself, make sure to include both u->v and v->u.
int cap[NN][NN], deg[NN], adj[NN][NN];

int dinic(int n, int s, int t) {
    // BFS stuff
    int q[NN], prev[NN];
    int flow = 0;

    while (true) {
        // find an augmenting path
        memset(prev, -1, sizeof(prev));
        int qf = 0, qb = 0;
        prev[q[qb++] = s] = -2;
        while (qb > qf && prev[t] == -1)
            for (int u = q[qf++], i = 0, v; i < deg[u]; i++)
                if (prev[v = adj[u][i]] == -1 && cap[u][v])
                    prev[q[qb++] = v] = u;

        // see if we're done
        if (prev[t] == -1)
            break;

        // try finding more paths
        for (int z = 0; z < n; z++)
            if (cap[z][t] && prev[z] != -1) {
                int bot = cap[z][t];
                for (int v = z, u = prev[v]; u >= 0; v = u, u = prev[v])
                    bot = min(bot, cap[u][v]);
                if (!bot)
                    continue;

                cap[z][t] -= bot;
                cap[t][z] += bot;
                for (int v = z, u = prev[v]; u >= 0; v = u, u = prev[v]) {
                    cap[u][v] -= bot;
                    cap[v][u] += bot;
                }
                flow += bot;
            }
    }

    return flow;
}

int main() {
    int test_cases;
    cin >> test_cases;

    for (int nt = 0; nt < test_cases; nt++) {
        int n, volunteers;
        cin >> n >> volunteers;

        int nv = 6 + volunteers + 2;

        memset(cap, 0, sizeof(cap));
        for (int i = 1; i < 7; i++)
            cap[0][i] = n / 6;

        string suit1, suit2;

        for (int m = 7; m < nv - 1; m++) {
            cin >> suit1 >> suit2;

            cap[m][nv - 1] = 1;

            if (suit1 == "XXL" || suit2 == "XXL")
                cap[1][m] = 1;
            if (suit1 == "XL" || suit2 == "XL")
                cap[2][m] = 1;
            if (suit1 == "L" || suit2 == "L")
                cap[3][m] = 1;
            if (suit1 == "M" || suit2 == "M")
                cap[4][m] = 1;
            if (suit1 == "S" || suit2 == "S")
                cap[5][m] = 1;
            if (suit1 == "XS" || suit2 == "XS")
                cap[6][m] = 1;
        }

        memset(deg, 0, sizeof(deg));
        for (int u = 0; u < nv; u++)
            for (int v = 0; v < nv; v++)
                if (cap[u][v] || cap[v][u]) {
                    adj[u][deg[u]++] = v;
                }

        cout << (dinic(nv, 0, nv - 1) == volunteers ? "YES" : "NO") << endl;
    }

    return 0;
}