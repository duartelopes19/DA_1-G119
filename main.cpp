#include <iostream>
#include "Empresa.h"

void menu(Empresa a) {
    int option;
    cout << endl << " Logistica Urbana para Entrega de Mercadorias" <<endl << endl;
    cout << "1 - Cenario 1: otimizacao do numero de estafetas" << endl;
    cout << "2 - Cenario 2: otimizacaoo do lucro da empresa" << endl;
    cout << "3 - Cenario 3: otimizacao das entregas expresso" << endl;
    cout << "4 - Sair" << endl<<endl;
    cout << "Opcao: ";
    cin >> option;
    switch (option) {
        case 1: a.otimizarNumeroEstafetas();
                a.registarCenario();
                a.registarCarrinhacarga();
            break;
        case 2: a.otimizarLucro();
                a.registarCenario();
                a.registarCarrinhacarga();
            break;

        case 3: a.otimizarEntregasExpresso();
                a.registarCenario();
                break;
        case 4: return;
        default: cout << endl << "Resposta invalida. Tente novamente.";
    }
    system("pause");
    system("cls");
    menu(a);
}



int main() {
    Empresa a;
    a.addCarrinhas("carrinhas.txt");
    a.addEncomendas("encomendas.txt");
    menu(a);
}
