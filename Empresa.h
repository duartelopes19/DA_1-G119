//
// Created by User on 07/04/2022.
//

#ifndef DA_T1_G119_EMPRESA_H
#define DA_T1_G119_EMPRESA_H

#include "Encomenda.h"
#include "Carrinha.h"
#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <queue>
#include <map>

using namespace std;

class Empresa {
private:
    vector<Carrinha> carrinhas;
    vector<Encomenda> encomendas;
public:
    Empresa();
    void addCarrinhas(string file);
    void addEncomendas(string file);
    queue<Encomenda> ordenarEncomendasPorEspaco();
    vector<Carrinha> ordenarCarrinhasPorCapacidade();
    queue<Encomenda> ordenarEncomendasPorRecompensa();
    vector<Carrinha> ordenarCarrinhasPorCusto();
    queue<Encomenda> ordenarEncomendasPorDuracao();
    void otimizarNumeroEstafetas();
    void otimizarLucro();
    void otimizarEntregasExpresso();
};


#endif //DA_T1_G119_EMPRESA_H
