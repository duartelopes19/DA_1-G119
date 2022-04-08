//
// Created by User on 07/04/2022.
//

#include "Empresa.h"

Empresa::Empresa() {}

void Empresa::addCarrinhas(string file) {
    string temp;
    int volMax, pesoMax, custo;

    ifstream fcarrinhas(file);

    getline(fcarrinhas,temp);
    while(!fcarrinhas.eof()) {
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
    string temp;
    int volume, peso, recompensa, duracao;

    ifstream fencomendas(file);

    getline(fencomendas,temp);
    while(!fencomendas.eof()) {
        getline(fencomendas,temp,' ');
        volume = stoi(temp);
        getline(fencomendas,temp,' ');
        peso = stoi(temp);
        getline(fencomendas,temp,' ');
        recompensa = stoi(temp);
        getline(fencomendas,temp,'\n');
        duracao = stoi(temp);
        Encomenda encomenda(volume,peso,recompensa,duracao);
        encomendas.push_back(encomenda);
    }
}

void Empresa::otimizarNumeroEstafetas() {

}

void Empresa::otimizarLucro() {

}

void Empresa::otimizarEntregasExpresso() {

}
