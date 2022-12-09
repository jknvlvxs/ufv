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
    int test_cases;
    string suit1, suit2;

    cin >> test_cases;

    for (int nt = 0; nt < test_cases; nt++) {
        int n, volunteers;

        cin >> n >> volunteers;

        for (int m = 0; m < volunteers; m++) {
            cin >> suit1 >> suit2;
            cout << suit1 << " " << suit2 << endl;
        }
    }

    return 0;
}