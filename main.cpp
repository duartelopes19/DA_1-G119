#include <iostream>
#include "Empresa.h"

int main() {
    Empresa empresa;
    empresa.addCarrinhas("dataset/carrinhas.txt");
    empresa.addEncomendas("dataset/encomendas.txt");
    return 1;
}
