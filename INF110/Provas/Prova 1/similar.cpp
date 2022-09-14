#include <iostream>

using namespace std;

int main () {
    int n;
    cin >> n;
    int pagina1[n], pagina2[n], pagina3[n], produto12 = 0, produto23 = 0, produto13 = 0;

    for(int i = 0; i < n; i++){
        cin >> pagina1[i];
    }

    for(int i = 0; i < n; i++){
        cin >> pagina2[i];
    }

    for(int i = 0; i < n; i++){
        cin >> pagina3[i];
    }

    for(int i = 0; i < n; i++){
        produto12 += pagina1[i] * pagina2[i];
        produto23 += pagina2[i] * pagina3[i];
        produto13 += pagina1[i] * pagina3[i];
    }   

    if (produto12 > produto23 && produto12 > produto23){
        cout << "1 2" << endl;
    } else if (produto23 > produto12 && produto23 > produto13) {
        cout << "2 3" << endl;
    } else {
        cout << "1 3" << endl;
    }
        
    return 0;
}