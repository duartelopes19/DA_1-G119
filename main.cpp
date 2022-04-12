#include <iostream>
#include "Empresa.h"

void menu(Empresa a) {
    int option;
    cout << "Logística Urbana para Entrega de Mercadorias" << endl << endl;
    cout << "1- Cenário 1: otimização do número de estafetas" << endl;
    cout << "2- Cenário 2: otimização do lucro da empresa" << endl;
    cout << "3- Cenário 3: otimização das entregas expresso" << endl;
    cout << "4- Sair" << endl;
    cin >> option;
    switch (option) {
        case 1: a.otimizarNumeroEstafetas(); break;
        case 2: a.otimizarLucro(); break;
        case 3: a.otimizarEntregasExpresso(); break;
        case 4: return;
        default:;
    }
    menu(a);
}

int main() {
    Empresa a;
    a.addCarrinhas("dataset/carrinhas.txt");
    a.addEncomendas("dataset/encomendas.txt");
    menu(a);
}
