// Universidade Federal de Viçosa - Ciência da Computação
// Disciplina: INF112 - Programação II
// Autor: José Júlio Alves Campolina
// Número de Matrícula: 102022 

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main () {
    try{
        ifstream fin;
        ofstream fout;

        fin.open("entrada.txt");
        fout.open("ips.txt");

        int n = 0;
        string *ips = new string[100];
        int ips_formatados[100][4];
        int ips_validos[100][4];
        int ips_invalidos[100][4];

        while(true){
            fin >> ips[n];
        if(fin.eof())
            break;
        else 
            n++;
        }

        string delimiter = ".";

        for(int i = 0; i <= n; i++){
                size_t pos = 0;
                std::string token;
                int nToken = 0;
                while ((pos = ips[i].find(delimiter)) != std::string::npos) {
                    token = ips[i].substr(0, pos);
                    ips_formatados[i][nToken] = stoi(token);
                    ips[i].erase(0, pos + delimiter.length());
                    nToken++;
                }
                ips_formatados[i][3] = stoi(ips[i]);
        }

        int num_validos = 0; 
        int num_invalidos = 0; 

        for(int i = 0; i <= n; i++){
            if(ips_formatados[i][0] > 0 && ips_formatados[i][0] < 255
                && ips_formatados[i][1] > 0 && ips_formatados[i][1] < 255
                && ips_formatados[i][2] > 0 && ips_formatados[i][2] < 255
                && ips_formatados[i][3] > 0 && ips_formatados[i][3] < 255){
                    ips_validos[num_validos][0] = ips_formatados[i][0];
                    ips_validos[num_validos][1] = ips_formatados[i][1];
                    ips_validos[num_validos][2] = ips_formatados[i][2];
                    ips_validos[num_validos][3] = ips_formatados[i][3];
                    num_validos++;
                } else {
                    ips_invalidos[num_invalidos][0] = ips_formatados[i][0];
                    ips_invalidos[num_invalidos][1] = ips_formatados[i][1];
                    ips_invalidos[num_invalidos][2] = ips_formatados[i][2];
                    ips_invalidos[num_invalidos][3] = ips_formatados[i][3];
                    num_invalidos++;
                }
        }

        fout << "[Endereços válidos:]" << endl;
        for(int i = 0; i < num_validos; i++){
            for(int j = 0; j < 4; j++){
                fout << ips_validos[i][j] << (j != 3 ? "." : "");
            }
            fout << endl;
        }

        fout << endl << "[Endereços inválidos:]" << endl;
        for(int i = 0; i < num_invalidos; i++){
            for(int j = 0; j < 4; j++){
                fout << ips_invalidos[i][j] << (j != 3 ? "." : "");
            }
            fout << endl;
        }

        delete[] ips;

        fin.close();
        fout.close();
    } catch (ifstream::failure *e) {
        cerr << "Exception opening/reading/closing file" << endl;
    } catch (ofstream::failure e) {
        cerr << "Exception opening/reading/closing file" << endl;
    }
    
    return 0;
}