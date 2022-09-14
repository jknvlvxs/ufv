#include <iostream>
#include <string>
#include "MyMap.h"

using namespace std;

int main() {
    MyMap<string,int> mapa;
    string elem;
    
    while(cin >> elem){
        if(mapa[elem] == 0)
            mapa[elem] = mapa.size();
            
        cout << elem << " " << mapa[elem]-1 << endl;
    }
}