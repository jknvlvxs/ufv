/*
README
Fontes de consulta: http://shygypsy.com/tools/flow.cpp
Pessoas com as quais discuti sobre este exercício: Samuel
*/
#include <algorithm>
#include <bits/stdc++.h>
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
 *      http://www.palmcommander.com:8081/tools/
 * LICENSE:
 *      http://www.palmcommander.com:8081/tools/LICENSE.html
 * Copyright (c) 2004
 * Contact author:
 *      igor at cs.ubc.ca
 **/

/****************
 * Maximum flow * (Ford-Fulkerson on an adjacency matrix)
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
 *      - fnet contains the flow network. Careful: both fnet[u][v] and
 *          fnet[v][u] could be positive. Take the difference.
 *      - prev contains the minimum cut. If prev[v] == -1, then v is not
 *          reachable from s; otherwise, it is reachable.
 * DETAILS:
 * FIELD TESTING:
 *      - Valladolid 10330: Power Transmission
 *      - Valladolid 653:   Crimewave
 *      - Valladolid 753:   A Plug for UNIX
 *      - Valladolid 10511: Councilling
 *      - Valladolid 820:   Internet Bandwidth
 *      - Valladolid 10779: Collector's Problem
 * #include <string.h>
 * #include <queue>
 **/

// the maximum number of vertices
#define NN 1024

// adjacency matrix (fill this up)
int cap[NN][NN];

// flow network
int fnet[NN][NN];

int fordFulkerson(int n, int s, int t) {
    // BFS
    int q[NN], qf, qb, prev[NN];
    // init the flow network
    memset(fnet, 0, sizeof(fnet));

    int flow = 0;

    while (true) {
        // find an augmenting path
        memset(prev, -1, sizeof(prev));
        qf = qb = 0;
        prev[q[qb++] = s] = -2;
        while (qb > qf && prev[t] == -1)
            for (int u = q[qf++], v = 0; v < n; v++)
                if (prev[v] == -1 && fnet[u][v] - fnet[v][u] < cap[u][v])
                    prev[q[qb++] = v] = u;

        // see if we're done
        if (prev[t] == -1)
            break;

        // get the bottleneck capacity
        int bot = 0x7FFFFFFF;
        for (int v = t, u = prev[v]; u >= 0; v = u, u = prev[v])
            bot = min(bot, cap[u][v] - fnet[u][v] + fnet[v][u]);

        // update the flow network
        for (int v = t, u = prev[v]; u >= 0; v = u, u = prev[v])
            fnet[u][v] += bot;

        flow += bot;
    }

    return flow;
}

int main() {

    int n;

    cin >> n;

    while (n != 0) {

        memset(cap, 0, sizeof(cap));

        int nv = n + n + 2;

        vector<int> capacity(n + 1, 0);

        for (int a = 1; a <= n; a++)
            cin >> capacity[a];

        int m, i, j, c;
        cin >> m;
        while (m--) {
            cin >> i >> j >> c;
            cap[i][i + n] = capacity[i];
            cap[i + n][j] += c;
        }

        int b, d, u;
        cin >> b >> d;

        while (b--) {
            cin >> u;
            cap[0][u] = INT_MAX;
        }

        while (d--) {
            cin >> u;
            cap[u][u + n] = capacity[u];
            cap[u + n][nv - 1] = INT_MAX;
        }

        cout << fordFulkerson(nv, 0, nv - 1) << endl;

        cin >> n;

        if (cin.eof())
            break;
    }

    return 0;
}