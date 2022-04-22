#include "Carrinha.h"

Carrinha::Carrinha(int id, int volMax, int pesoMax, int custo) : id(id), volMax(volMax), pesoMax(pesoMax), custo(custo) {}

int Carrinha::getIdCar() const {
    return id;
}

int Carrinha::getVolMax() const {
    return volMax;
}

int Carrinha::getPesoMax() const {
    return pesoMax;
}

int Carrinha::getCusto() const {
    return custo;
}

void Carrinha::setIdCar(int id) {
    Carrinha::id = id;
}

void Carrinha::setVolMax(int volMax) {
    Carrinha::volMax = volMax;
}

void Carrinha::setPesoMax(int pesoMax) {
    Carrinha::pesoMax = pesoMax;
}

void Carrinha::setCusto(int custo) {
    Carrinha::custo = custo;
}


