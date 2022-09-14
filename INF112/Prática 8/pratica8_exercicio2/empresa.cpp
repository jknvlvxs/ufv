// Universidade Federal de Viçosa - Ciência da Computação
// Disciplina: INF112 - Programação II
// Autor: José Júlio Alves Campolina
// Número de Matrícula: 102022 

#include <fstream>
#include <string>
#include <iomanip>
#include <string.h>
#include <math.h>  
#include "empresa.h"
#include "funcionario.h"

Empresa::Empresa(std::string fin_name, std::string fout_name){

    fin.open(fin_name);
    fout.open(fout_name);

    std::vector<char*> leitura;
    std::string buffer;

    while(!fin.eof()){
        getline(fin, buffer);
        char *linha = (char*)buffer.c_str();

        char *palavra = strtok (linha,"R$ ,.-");
        std::string nome = palavra;

        palavra = strtok (NULL, "R$");
        double gasto = atof(palavra);

        Funcionario f(funcionarios.size()+1, nome, gasto);
        funcionarios.push_back(f);
        gasto_total += gasto;
    }

    fout << std::fixed;

    fout << "Nro. Funcionario Gasto %" << std::endl;
    for (int i = 0; i < funcionarios.size(); i++){
        fout << funcionarios[i].get_id() << " ";
        fout << funcionarios[i].get_nome() << " R$";
        fout << std::setprecision(2) << funcionarios[i].get_gasto() << " ";
        fout << std::setprecision(0) << std::round(funcionarios[i].get_gasto()*100/gasto_total) << "%" << std::endl;
    }
    fout << std::setprecision(2) << "Gasto mensal total: R$" << gasto_total << std::endl;
    fout << std::setprecision(2) << "Gasto médio por funcionário: R$" << gasto_total/funcionarios.size() << std::endl;
}