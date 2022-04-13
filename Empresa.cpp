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

queue<Encomenda> Empresa::ordenarEncomendasPorEspaco() {
    map<int,Encomenda> mEncomendas;
    queue<Encomenda> qEncomendas;

    for(Encomenda encomenda : encomendas) {
        int a = encomenda.getVolume()*encomenda.getPeso();
        while(mEncomendas.contains(a)) {
            a++;
        }
        mEncomendas.insert(pair(a,encomenda));
    }

    for(auto encomenda : mEncomendas) {
        qEncomendas.push(encomenda.second);
    }

    return qEncomendas;
}

vector<Carrinha> Empresa::ordenarCarrinhasPorCapacidade() {
    map<int,Carrinha> mCarrinhas;
    vector<Carrinha> estafetas;

    for(Carrinha carrinha : carrinhas) {
        int a = 0-(carrinha.getPesoMax()*carrinha.getVolMax());
        while(mCarrinhas.contains(a)) {
            a++;
        }
        mCarrinhas.insert(pair(a,carrinha));
    }

    for(auto carrinha : mCarrinhas) {
        estafetas.push_back(carrinha.second);
    }

    return estafetas;
}

queue<Encomenda> Empresa::ordenarEncomendasPorRecompensa(){
    map<int,Encomenda> mEncomendas;
    queue<Encomenda> qEncomendas;

    for(Encomenda encomenda : encomendas) {
        int a = (0-(encomenda.getPeso()*encomenda.getVolume()))*encomenda.getRecompensa();
        while(mEncomendas.contains(a)) {
            a++;
        }
        mEncomendas.insert(pair(a,encomenda));
    }

    for(auto encomenda : mEncomendas) {
        qEncomendas.push(encomenda.second);
    }

    return qEncomendas;
}

vector<Carrinha> Empresa::ordenarCarrinhasPorCusto() {
    map<int,Carrinha> mCarrinhas;
    vector<Carrinha> estafetas;

    for(Carrinha carrinha : carrinhas) {
        int a = carrinha.getVolMax()*carrinha.getPesoMax()*(0-carrinha.getCusto());
        while(mCarrinhas.contains(a)) {
            a++;
        }
        mCarrinhas.insert(pair(a,carrinha));
    }

    for(auto carrinha : mCarrinhas) {
        estafetas.push_back(carrinha.second);
    }

    return estafetas;
}

queue<Encomenda> Empresa::ordenarEncomendasPorDuracao() {
    map<int,Encomenda> mEncomendas;
    queue<Encomenda> qEncomendas;

    for(Encomenda encomenda : encomendas) {
        int a = encomenda.getDuracao();
        while(mEncomendas.contains(a)) {
            a++;
        }
        mEncomendas.insert(pair(a,encomenda));
    }

    for(auto encomenda : mEncomendas) {
        qEncomendas.push(encomenda.second);
    }

    return qEncomendas;
}

void Empresa::otimizarNumeroEstafetas() {
    queue<Encomenda> qEncomendas = ordenarEncomendasPorEspaco();
    vector<Carrinha> estafetas = ordenarCarrinhasPorCapacidade();
    int carrinhasUsadas = 0, encomendasCarregadas, volume, peso;

    for(Carrinha carrinha : estafetas) {
        carrinhasUsadas++;
        encomendasCarregadas = 0;
        while(!qEncomendas.empty())  {
            Encomenda encomenda = qEncomendas.front();
            volume = carrinha.getVolMax()-encomenda.getVolume();
            peso = carrinha.getPesoMax()-encomenda.getPeso();
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
    queue<Encomenda> qEncomendas = ordenarEncomendasPorRecompensa();
    vector<Carrinha> estafetas = ordenarCarrinhasPorCusto();
    int carrinhasUsadas = 0, encomendasCarregadas, ganhos = 0, despesas = 0, volume, peso;

    for(Carrinha carrinha : estafetas) {
        carrinhasUsadas++;
        encomendasCarregadas = 0;
        despesas += carrinha.getCusto();
        while(!qEncomendas.empty())  {
            Encomenda encomenda = qEncomendas.front();
            volume = carrinha.getVolMax()-encomenda.getVolume();
            peso = carrinha.getPesoMax()-encomenda.getPeso();
            if(volume>=0 && peso>=0) {
                carrinha.setVolMax(volume);
                carrinha.setPesoMax(peso);
                encomendasCarregadas++;
                ganhos += encomenda.getRecompensa();
                qEncomendas.pop();
            } else { break; }
        }
        cout << "Na " << carrinhasUsadas << "ª carrinha foram carregadas " << encomendasCarregadas << " encomendas." << endl;
        if(qEncomendas.empty()) { break; }
    }
    cout << "Foram distribuídas " << (encomendas.size()-qEncomendas.size()) << " encomendas por " << carrinhasUsadas << " estafetas. Sobrando " << qEncomendas.size() << " encomendas e ficando " << carrinhas.size()-carrinhasUsadas << " estafetas livres." << endl << "O que custou à empresa " << despesas << "€ mas originou um retorno de " << ganhos << "€, contribuindo assim para um lucro de " << ganhos-despesas << "€." << endl << endl;
}

void Empresa::otimizarEntregasExpresso() {
    queue<Encomenda> qEncomendas = ordenarEncomendasPorDuracao();
    int viagensFeitas = 0, tempoDecorrido = 0;

    while(!qEncomendas.empty()) {
        Encomenda encomenda = qEncomendas.front();
        tempoDecorrido += encomenda.getDuracao();
        if(tempoDecorrido>28800) {
            tempoDecorrido -= encomenda.getDuracao();
            break;
        } else {
            viagensFeitas++;
            qEncomendas.pop();
        }
    }
    cout << "Foram entregues " << viagensFeitas << " encomendas num total de " << tempoDecorrido/3600 << " horas entre as 9:00 e as 17:00." << endl << endl;
}

