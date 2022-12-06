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
    // visitou[origem] = true;

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

bool canWalk(vector<int> const &cat_d, vector<int> const &rat_d, int number_of_rooms, vector<vector<int>> rat_doors) {
    int counter = 0;

    cout << endl;
    for (int i = 0; i < number_of_rooms; i++)
        cout << cat_d[i] << " ";
    cout << endl;
    for (int i = 0; i < number_of_rooms; i++)
        cout << rat_d[i] << " ";
    cout << endl;

    for (int i = 0; i < number_of_rooms; i++)
        if (cat_d[i] == -1 && rat_d[i] != -1)
            counter++;

    return counter >= 2;
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

        int u, v;
        int reverse = false;

        string c;
        cin.ignore();

        while (getline(cin, c)) {
            if (c == "")
                break;

            stringstream ss(c);
            ss >> u >> v;

            if (u == -1 && v == -1)
                reverse = true;
            else {
                if (!reverse)
                    cat_doors[u - 1].push_back(v - 1);
                else
                    rat_doors[u - 1].push_back(v - 1);
            }
        }

        vector<int> cat_distances(number_of_rooms, -1);
        vector<int> rat_distances(number_of_rooms, -1);

        vector<bool> cat_visited(cat_doors.size(), false);
        vector<bool> rat_visited(rat_doors.size(), false);

        distances(cat_doors, cat_distances, cat_visited, cat_room - 1);
        distances(rat_doors, rat_distances, rat_visited, rat_room - 1);

        // meet each other
        bool meet = meetEachOther(number_of_rooms, cat_distances, rat_distances);
        cout << (meet ? "Y" : "N") << " ";

        // mouse can walk without being caught
        bool can_walk = rat_visited[rat_room - 1] && (cat_room != rat_room) && canWalk(cat_distances, rat_distances, number_of_rooms, rat_doors);
        cout << (can_walk ? "Y" : "N") << endl;

        cout << endl;
    }

    return 0;
}