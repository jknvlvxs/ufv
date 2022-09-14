#include <iostream>

using namespace std;

int mdc(int a, int b){
    if (b == 0) return a;
    else return mdc(b, a % b);
}
 
int mmc(int a, int b) {
    return (a / mdc(a, b)) * b;
}

void somafrac(int na, int da, int nb, int db, int &nr, int &dr){
    dr = mmc(da, db);
    nr = (dr / da * na) + (dr / db * nb); 

    for(int i = nr; i > 0; i--){
        if(nr%i == 0 && dr%i == 0){
            nr /= i;
            dr /=  i;
        }
    }
}

int main() {
    int na = 0, da = 0, nb = 0, db = 0, nr = 0, dr = 0;
    char c;
    cin >> na >> c >> da;
    cin >> nb >> c >> db;

    somafrac(na, da, nb, db, nr, dr);
    cout << na << "/" << da << "+" << nb << "/" << db << "=" << nr << "/" << dr << endl;

    return 0;
}