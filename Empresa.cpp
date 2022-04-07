//
// Created by User on 07/04/2022.
//

#include <fstream>
#include "Empresa.h"

Empresa::Empresa() {}

void Empresa::addCarrinhas(string file) {
    string temp;
    int volMax, pesoMax, custo;

    ifstream fcarrinhas(file);

    getline(fcarrinhas,temp);
    while(!fcarrinhas.eof() && fcarrinhas.is_open()) {
        getline(fcarrinhas,temp,' ');
        volMax = stoi(temp);
        getline(fcarrinhas,temp,' ');
        pesoMax = stoi(temp);
        getline(fcarrinhas,temp,'\n');
        custo = stoi(temp);
        Carrinha carrinha(volMax,pesoMax,custo);
        carrinhas.push_back(carrinha);
    }
}

void Empresa::addEncomendas(string file) {
/*    string tmp, volume, peso, recompensa, duracao;
    ifstream fencomenda(file);
    getline(fencomenda,tmp);
    while(!fencomenda.eof()) {
        getline(fencomenda,volume,' ');
        getline(fencomenda,peso,' ');
        getline(fencomenda,recompensa,' ');
        getline(fencomenda,duracao,'\n');
        Encomenda encomenda(stoi(volume),stoi(peso),stoi(recompensa),stoi(duracao));
        encomendas.push_back(encomenda);
    }*/
}
