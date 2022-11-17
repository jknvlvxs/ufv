/*
README
Fontes de consulta:
Pessoas com as quais discuti sobre este exercício:
*/
#include <iostream>
#include <vector>
#include <iostream>
#include <string>
#include <map>
#include <queue>

using namespace std;

int adicionaAresta(vector<string> &palavras, map<char, vector<char>> &adj)
{
    for (int i = 0; i < palavras.size() - 1; i++)
    {
        string palavra1 = palavras[i];
        string palavra2 = palavras[i + 1];
        int j = 0;
        while (j < palavra1.size() && j < palavra2.size())
        {
            if (palavra1[j] != palavra2[j])
            {
                adj[palavra1[j]].push_back(palavra2[j]);
                break;
            }
            j++;
        }
    }
}

int main()
{

    vector<string> palavras;
    string st;

    while (getline(cin, st))
    {
        if (st == "#")
            break;
        palavras.push_back(st);
    }

    // Create a graph
    map<char, vector<char>> adj;

    adicionaAresta(palavras, adj);

    // Print the graph
    // for (auto it = graph.begin(); it != graph.end(); it++)
    // {
    //     cout << it->first << " -> ";
    //     for (int i = 0; i < it->second.size(); i++)
    //     {
    //         cout << it->second[i] << " ";
    //     }
    //     cout << endl;
    // }
    // cout << endl;

    // Create a map to store indegrees of all
    // vertices. Initialize all indegrees as 0.
    map<char, int>
        grau_vertice;

    // Traverse adjacency lists to fill indegrees of
    // vertices.  This step takes O(V+E) time
    for (auto it = adj.begin(); it != adj.end(); it++)
    {
        grau_vertice[it->first] = 0;
        for (int i = 0; i < it->second.size(); i++)
            grau_vertice[it->second[i]]++;
    }

    // Print the indegrees
    // for (auto it = in_degree.begin(); it != in_degree.end(); it++)
    // {
    //     cout << it->first << " -> " << it->second << endl;
    // }

    // Create an queue and enqueue all vertices with
    // indegree 0
    queue<char> q;
    for (auto it = grau_vertice.begin(); it != grau_vertice.end(); it++)
    {
        if (it->second == 0)
        {
            q.push(it->first);
        }
    }

    // Create a vector to store result (A topological
    // ordering of the vertices)
    vector<char> top_order;

    // One by one dequeue vertices from queue and enqueue
    // adjacents if indegree of adjacent becomes 0

    while (!q.empty())
    {
        // Extract front of queue (or perform dequeue)
        // and add it to topological order
        char u = q.front();
        q.pop();
        top_order.push_back(u);

        // Iterate through all its neighbouring nodes
        // of dequeued node u and decrease their in-degree
        // by 1
        for (int i = 0; i < adj[u].size(); i++)
            if (--grau_vertice[adj[u][i]] == 0)
                q.push(adj[u][i]);

        // If in-degree becomes zero, add it to queue
    }

    // Print topological order
    for (int i = 0; i < top_order.size(); i++)
    {
        cout << top_order[i];
    }

    cout << endl;

    return 0;
}
