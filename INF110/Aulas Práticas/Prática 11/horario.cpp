#include <iostream>
#include <iomanip>

using namespace std;

struct Horario {
    int horas, minutos;
};

void escreve (Horario h) {
    char *sigla = " AM";

    if(h.horas >= 12) {
        sigla = " PM";
        if(h.horas != 12){
            h.horas = h.horas - 12;
        }
    } else if (h.horas == 0){
        h.horas = 12;
    }

    cout << setfill('0') << setw(2) << h.horas << ":" << setfill('0') << setw(2) << h.minutos << sigla << endl;
}

int main() {
    int n;
    cin >> n;
    Horario horarios[n];

    for(int i = 0; i < n; i++){
        cin >> horarios[i].horas;
        cin >> horarios[i].minutos;
        cin.ignore();
    }

    for(int i = 0; i < n; i++){
        escreve(horarios[i]);
    }
    
    return 0;
}