#include <iostream>

using namespace std;

struct Aluno {
    int matricula, nota;
};

int main() {
    int t; 
    cin >> t;
    Aluno alunos[t];

    for(int i = 0; i < t; i++) {
        cin >> alunos[i].matricula;
        cin >> alunos[i].nota;
        cin.ignore();
    }

    for(int i = 0; i < t-1; i++) {
        for(int j = 0; j < t-1; j++) {
            if(alunos[j].matricula > alunos[j+1].matricula){
                Aluno aux = {alunos[j].matricula, alunos[j].nota};
                alunos[j] = alunos[j+1];
                alunos[j+1] = aux;
            }
        }
    }

    for(int i = 0; i < t; i++)
        cout << alunos[i].matricula << " " << alunos[i].nota << endl;

    return 0;
}