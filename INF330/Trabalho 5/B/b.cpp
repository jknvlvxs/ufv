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

int main() {

    int number_of_regulators, number_of_links;

    vector<int> capacity(number_of_regulators);

    // for (int n = 0; n < number_of_regulators; n++)
    for (auto &b : capacity)
        cin >> b;

    cin >> number_of_links;

    int i, j, c;

    for (int m = 0; m < number_of_links; m++) {
        cin >> i >> j >> c;
    }

    int b, d;

    cin >> b, d;

    vector<int> index(b + d);

    for (auto &bd : index)
        cin >> bd;

    return 0;
}