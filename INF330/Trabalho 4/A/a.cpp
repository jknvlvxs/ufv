/*
README
Fontes de consulta:
Pessoas com as quais discuti sobre este exercício:
*/
#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

void distances(vector<vector<int>> const &doors, vector<int> &distances, vector<bool> &visitou, int origem) {
    distances[origem] = 0;

    vector<int> queue;
    queue.push_back(origem);
    visitou[origem] = true;

    while (!queue.empty()) {
        int v = queue.back();
        queue.pop_back();

        for (int i = 0; i < doors[v].size(); i++) {
            int x = doors[v][i];
            if (!visitou[x]) {
                visitou[x] = true;
                distances[x] = distances[v] + 1;
                queue.push_back(x);
            }
        }
    }
}

bool meetEachOther(int number_of_rooms, vector<int> &cat_d, vector<int> &rat_d) {
    for (int i = 0; i < number_of_rooms; i++)
        if (cat_d[i] != -1 && rat_d[i] != -1)
            return true;

    return false;
}

bool canWalk(vector<vector<int>> &only_rat_doors, int number_of_rooms, int rat_room) {
    vector<int> only_rat_distances(number_of_rooms, -1);
    vector<bool> only_rat_visited(only_rat_doors.size(), false);
    vector<int> queue;

    queue.push_back(rat_room);

    while (!queue.empty()) {
        int v = queue.back();
        queue.pop_back();

        for (int i = 0; i < only_rat_doors[v].size(); i++) {
            int x = only_rat_doors[v][i];
            if (!only_rat_visited[x]) {
                only_rat_visited[x] = true;
                only_rat_distances[x] = only_rat_distances[v] + 1;
                queue.push_back(x);
            }
        }
    }

    return only_rat_distances[rat_room] != -1;
}

int main() {
    int n; // Number of test cases

    cin >> n;

    cin.ignore();

    int number_of_rooms, cat_room, rat_room;

    for (int i = 0; i < n; i++) {
        cin >> number_of_rooms >> cat_room >> rat_room;

        vector<vector<int>> cat_doors(number_of_rooms);
        vector<vector<int>> rat_doors(number_of_rooms);
        vector<vector<int>> only_rat_doors(number_of_rooms); // rat doors that are not visited by cat

        int u, v;
        int reading_rats = false;

        string c;
        cin.ignore();

        vector<int> cat_distances(number_of_rooms, -1);
        vector<bool> cat_visited(cat_doors.size(), false);

        while (getline(cin, c)) {
            if (c == "")
                break;

            stringstream ss(c);
            ss >> u >> v;

            if (u == -1 && v == -1) {
                reading_rats = true;
                distances(cat_doors, cat_distances, cat_visited, cat_room - 1);
            } else {
                if (!reading_rats)
                    cat_doors[u - 1].push_back(v - 1);
                else {
                    rat_doors[u - 1].push_back(v - 1);

                    if (!cat_visited[u - 1] && !cat_visited[v - 1])
                        only_rat_doors[u - 1].push_back(v - 1);
                }
            }
        }

        vector<int> rat_distances(number_of_rooms, -1);
        vector<bool> rat_visited(rat_doors.size(), false);
        distances(rat_doors, rat_distances, rat_visited, rat_room - 1);

        // meet each other
        bool meet = meetEachOther(number_of_rooms, cat_distances, rat_distances);
        cout << (meet ? "Y" : "N") << " ";

        // mouse can walk without being caught
        bool can_walk = canWalk(only_rat_doors, number_of_rooms, rat_room - 1);
        cout << (can_walk ? "Y" : "N") << endl;

        if (i != n - 1)
            cout << endl;
    }

    return 0;
}