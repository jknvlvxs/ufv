#include <iostream>
#include <string>
#include "MySet.h"
#include "MyVecNewIterator.h"

using namespace std;

int main(int argc, char**argv) {
    string arg = argv[1];

    string elem;
    int repetidos = 0;

    if(arg == "myset"){
        MySet<string> tree;

        while(cin >> elem){
            if(!tree.insert(elem).second)
                repetidos++;
        }

        cout << tree.size() + repetidos << " " << tree.size() << endl; 
    } else {
        MyVec<string> container;

        while(cin >> elem){
            int pos = 0;
            
            for(int i = 0; i < container.size(); i++){
                if(container[pos] == elem) break;
                pos++;
            }

            if(container.size() == pos) container.push_back(elem);
            else repetidos++;
        }

        cout << container.size() + repetidos << " " << container.size() << endl; 
    }
}