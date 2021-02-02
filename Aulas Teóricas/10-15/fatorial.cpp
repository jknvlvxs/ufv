#include <iostream>
using namespace std;

long long int fatorial (int n) {
    long long int nfatorial = 1;

    for(int i = n; i >= 1; i--){
        nfatorial = nfatorial * i;
    }

    return nfatorial;
}

int main () {
    int n;
    cin >> n;
    cout << fatorial(n) << endl;
    return 0;
}