#include "Empresa.h"

Empresa::Empresa() {}



void Empresa::addCarrinhas(string file) {
    string temp;
    int id=0;
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

        Carrinha carrinha(id,volMax,pesoMax,custo);
        carrinhas.push_back(carrinha);

    }

}

void Empresa::addEncomendas(string file) {
    string temp;
    int idm=0;
    int idvol=0;
    int volume, peso, recompensa, duracao;
    encomendas.clear();

    ifstream fencomendas(file);
    getline(fencomendas,temp);
    while(!fencomendas.eof()) {
        idvol++;
        getline(fencomendas,temp,' ');
        volume = stoi(temp);
        getline(fencomendas,temp,' ');
        peso = stoi(temp);
        getline(fencomendas,temp,' ');
        recompensa = stoi(temp);
        getline(fencomendas,temp,'\n');
        duracao = stoi(temp);
        Encomenda encomenda(idm,idvol,volume,peso,recompensa,duracao);
        encomendas.push_back(encomenda);

    }
}

void Empresa::registarCenario(){

        ofstream file;
        file.open("cenario.txt", ofstream::out | ofstream::trunc);
        if (!file.is_open()) {
            cerr << "Ficheiro nao esta disponivel";

            exit(1);
        }


        file <<"idc   " << "ide    " <<"volume " << "peso  " << "recompensa " << "duracao"<<endl;

        for(const auto& encomenda : manifesto){


            file << encomenda.getIdm();
            file << " ";
            file << encomenda.getIdvol();
            file << " ";
            file << encomenda.getVolume();
            file << " ";
            file << encomenda.getPeso();
            file << " ";
            file << encomenda.getRecompensa();
            file << " ";
            file << encomenda.getDuracao();

            file << endl;

        }


        file.close();


}

void Empresa::registarCarrinhacarga(){


       // manifesto

        ofstream file;
        file.open("carga.txt", ofstream::out | ofstream::trunc);
        if (!file.is_open()) {
            cerr << "Ficheiro nao esta disponivel";

            exit(1);
        }


        file <<"id_carrinha " << "volume_total " <<"peso_total " <<endl;

        for(const auto& carrinha : carga){


            file << carrinha.getIdCar();
            file << " ";

            file << carrinha.getVolMax();
            file << " ";
            file << carrinha.getPesoMax();
            file << " ";

            file << endl;

        }


        file.close();


}


queue<Encomenda> Empresa::ordenarEncomendasPorEspaco() {
    multimap<int,Encomenda> mEncomendas;
    queue<Encomenda> qEncomendas;

    for(Encomenda encomenda : encomendas) {
        int a = encomenda.getVolume()*encomenda.getPeso();
        mEncomendas.insert(make_pair(a,encomenda));
    }

    for(auto encomenda : mEncomendas) {
        qEncomendas.push(encomenda.second);
    }

    return qEncomendas;
}

vector<Carrinha>Empresa::ordenarCarrinhasPorCapacidade() {
    multimap<int,Carrinha> mCarrinhas;
    vector<Carrinha> estafetas;

    for(Carrinha carrinha : carrinhas) {
        int a = carrinha.getPesoMax()*carrinha.getVolMax();
        mCarrinhas.insert(make_pair(-a,carrinha));
    }

    for(auto carrinha : mCarrinhas) {
        estafetas.push_back(carrinha.second);
    }

    return estafetas;
}

queue<Encomenda>Empresa::ordenarEncomendasPorRecompensa(){
    multimap<double,Encomenda> mEncomendas;
    queue<Encomenda> qEncomendas;

    for(Encomenda encomenda : encomendas) {
        double a = (double) (encomenda.getPeso()*encomenda.getVolume())/encomenda.getRecompensa();

        mEncomendas.insert(make_pair(a,encomenda));
    }

    for(auto encomenda : mEncomendas) {
        qEncomendas.push(encomenda.second);
    }

    return qEncomendas;
}

vector<Carrinha>Empresa::ordenarCarrinhasPorCusto() {
    multimap<double,Carrinha> mCarrinhas;
    vector<Carrinha> estafetas;

    for(Carrinha carrinha : carrinhas) {

        double a =(double)(carrinha.getVolMax()*carrinha.getPesoMax())/carrinha.getCusto();

        mCarrinhas.insert(make_pair(-a,carrinha));
    }

    for(auto carrinha : mCarrinhas) {
        estafetas.push_back(carrinha.second);
    }

    return estafetas;
}

queue<Encomenda>Empresa::ordenarEncomendasPorDuracao() {
    multimap<int,Encomenda> mEncomendas;
    queue<Encomenda> qEncomendas;

    for(Encomenda encomenda : encomendas) {
        int a = encomenda.getDuracao();
        mEncomendas.insert(make_pair(a,encomenda));
    }

    for(auto encomenda : mEncomendas) {
        qEncomendas.push(encomenda.second);
    }

    return qEncomendas;
}

void Empresa::otimizarNumeroEstafetas() {
    queue<Encomenda> qEncomendas = ordenarEncomendasPorEspaco();
    vector<Carrinha> estafetas = ordenarCarrinhasPorCapacidade();
    int carrinhasUsadas = 0, volume, peso, recompensa, duracao;

    for(Carrinha carrinha : estafetas) {
        if(qEncomendas.empty()) { break; }

        int t_peso=0;
        int t_volume=0;

        carrinhasUsadas++;

        while(!qEncomendas.empty())  {
            Encomenda encomenda = qEncomendas.front();
            volume = carrinha.getVolMax()-encomenda.getVolume();
            peso = carrinha.getPesoMax()-encomenda.getPeso();

            t_peso=t_peso+encomenda.getPeso();
            t_volume=t_volume+encomenda.getVolume();

            manifesto.emplace_back(carrinhasUsadas, encomenda.getIdvol(), encomenda.getVolume(), encomenda.getPeso(), encomenda.getRecompensa(), encomenda.getDuracao());

                if(volume>=0 && peso>=0) {
                carrinha.setVolMax(volume);
                carrinha.setPesoMax(peso);
                qEncomendas.pop();

            } else { break; }
        }
           carga.emplace_back(carrinhasUsadas, t_volume, t_peso,0);

    }
    cout << "Foram distribuídas " << (encomendas.size()-qEncomendas.size()) << " encomendas por " << carrinhasUsadas << " estafetas." << endl;
    cout << "Sobrando " << qEncomendas.size() << " encomendas e ficando " << carrinhas.size()-carrinhasUsadas << " estafetas livres." << endl<<endl;




}

void Empresa::otimizarLucro() {
    queue<Encomenda> qEncomendas = ordenarEncomendasPorRecompensa();
    vector<Carrinha> estafetas = ordenarCarrinhasPorCusto();
    int carrinhasUsadas = 0, encomendasCarregadas, ganhos = 0, despesas = 0, volume, peso, lucro, encomendasEntregues = 0;

    for(Carrinha carrinha : estafetas) {
        if(qEncomendas.empty()) { break; }

        int t_peso=0;
        int t_volume=0;

        lucro = ganhos-despesas;
        carrinhasUsadas++;
        encomendasCarregadas = 0;
        despesas += carrinha.getCusto();

        while(!qEncomendas.empty())  {
            Encomenda encomenda = qEncomendas.front();
            volume = carrinha.getVolMax()-encomenda.getVolume();
            peso = carrinha.getPesoMax()-encomenda.getPeso();

            t_peso=t_peso+encomenda.getPeso();
            t_volume=t_volume+encomenda.getVolume();

            manifesto.emplace_back(carrinhasUsadas, encomenda.getIdvol(), encomenda.getVolume(), encomenda.getPeso(), encomenda.getRecompensa(), encomenda.getDuracao());


            if(volume>=0 && peso>=0) {
                carrinha.setVolMax(volume);
                carrinha.setPesoMax(peso);
                encomendasCarregadas++;
                ganhos += encomenda.getRecompensa();
                qEncomendas.pop();

            } else { break; }
        }
        encomendasEntregues += encomendasCarregadas;
        if(lucro>(ganhos-despesas)) {
            carrinhasUsadas--;
            encomendasEntregues -= encomendasCarregadas;
            break;
        }
        lucro = ganhos-despesas;

        carga.emplace_back(carrinhasUsadas, t_volume, t_peso,0);

    }
    cout << "Foram distribuídas " << encomendasEntregues << " encomendas por " << carrinhasUsadas << " estafetas." << endl;
    cout << "Sobrando " << encomendas.size()-encomendasEntregues << " encomendas e ficando " << carrinhas.size()-carrinhasUsadas << " estafetas livres." << endl << "O que originou um lucro de " << lucro << "€." << endl << endl;
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

            manifesto.emplace_back(viagensFeitas, encomenda.getIdvol(), encomenda.getVolume(), encomenda.getPeso(), encomenda.getRecompensa(), encomenda.getDuracao());


            qEncomendas.pop();
        }
    }
    cout << "Foram entregues " << viagensFeitas << " encomendas num total de " << (double)tempoDecorrido/3600 << " horas entre as 9:00 e as 17:00." << endl;
    cout << "Sobrando então " << qEncomendas.size() << " encomendas que irão ser retornadas ao fornecedor." << endl << endl;
}

