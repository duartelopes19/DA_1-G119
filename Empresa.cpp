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
    std::sort(carrinhas.begin(), carrinhas.end());
    std::sort(encomendas.begin(), encomendas.end());

    queue<Encomenda> qEncomendas;
    for(Encomenda encomenda : encomendas) {
        qEncomendas.push(encomenda);
    }

    int carrinhasUsadas = 0;
    int encomendasCarregadas;
    for(Carrinha carrinha : carrinhas) {
        carrinhasUsadas++;
        encomendasCarregadas = 0;
        while(carrinha.getVolMax()!=0 || carrinha.getPesoMax()!=0) {
            if(qEncomendas.empty()) { break; }
            int volume = carrinha.getVolMax()-qEncomendas.front().getVolume();
            int peso = carrinha.getPesoMax()-qEncomendas.front().getPeso();
            if(volume>=0 && peso>=0) {
                carrinha.setVolMax(volume);
                carrinha.setPesoMax(peso);
                qEncomendas.pop();
                encomendasCarregadas++;
            } else { break; }
        }
        cout << "Na " << carrinhasUsadas << "ª carrinha foram carregadas " << encomendasCarregadas << " encomendas." << endl;
        if(qEncomendas.empty()) { break; }
    }
    cout << "Foram distribuídas " << (encomendas.size()-qEncomendas.size()) << " encomendas por " << carrinhasUsadas << " estafetas. Sobrando " << qEncomendas.size() << " encomendas e ficando " << carrinhas.size()-carrinhasUsadas << " estafetas livres." << endl;
}

void Empresa::otimizarLucro() {

}

void Empresa::otimizarEntregasExpresso() {

}
