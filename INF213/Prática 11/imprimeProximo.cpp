#include <iostream>
#include "MySet.h"

using namespace std;

int main() {
	MySet<int> database;
    
    string operation;
    int elem;

    while(cin >> operation >> elem){
        if(operation == "C") database.insert(elem);
        else if (operation == "S")
            if(database.find(elem)!=database.end() && ++database.find(elem)!=database.end()) cout << *(++database.find(elem)) << endl;
            else cout << "FALHA" << endl;
    }
}

/*
5 (o banco de dados possui 1,4,5,10)
FALHA (9 não está cadastrado ainda…)
FALHA (10 não possui sucessor cadastrado)
10 (o banco de dados possui 1,4,5,9,10)
4 (o banco de dados possui 1,4,5,9,10)
*/