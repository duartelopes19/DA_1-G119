//
// Created by User on 07/04/2022.
//

#include "Empresa.h"

Empresa::Empresa() {}

void Empresa::addCarrinhas(string file) {
    string temp;
    int volMax, pesoMax, custo;
    carrinhas.clear();

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
    encomendas.clear();

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

    map<int,Carrinha> mCarrinhas;
    for(Carrinha carrinha : carrinhas) {
        int a = 0-(carrinha.getPesoMax()*carrinha.getVolMax());
        mCarrinhas.insert(pair(a,carrinha));
    }

    map<int,Encomenda> mEncomendas;
    for(Encomenda encomenda : encomendas) {
        int a = encomenda.getVolume()*encomenda.getPeso();
        mEncomendas.insert(pair(a,encomenda));
    }

    queue<Encomenda> qEncomendas;
    for(auto encomenda : mEncomendas) {
        qEncomendas.push(encomenda.second);
    }

    vector<Carrinha> estafetas;
    for(auto carrinha : mCarrinhas) {
        estafetas.push_back(carrinha.second);
    }

    int carrinhasUsadas = 0;
    int encomendasCarregadas;
    for(Carrinha carrinha : carrinhas) {
        carrinhasUsadas++;
        encomendasCarregadas = 0;
        while((carrinha.getVolMax()!=0 || carrinha.getPesoMax()!=0) && !qEncomendas.empty())  {
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
    cout << "Foram distribuídas " << (encomendas.size()-qEncomendas.size()) << " encomendas por " << carrinhasUsadas << " estafetas. Sobrando " << qEncomendas.size() << " encomendas e ficando " << carrinhas.size()-carrinhasUsadas << " estafetas livres." << endl << endl;
}

void Empresa::otimizarLucro() {

}

void Empresa::otimizarEntregasExpresso() {

}
