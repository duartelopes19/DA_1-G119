//
// Created by User on 07/04/2022.
//

#include "Carrinha.h"

Carrinha::Carrinha(int volMax, int pesoMax, int custo) : volMax(volMax), pesoMax(pesoMax), custo(custo) {}

int Carrinha::getVolMax() const {
    return volMax;
}

int Carrinha::getPesoMax() const {
    return pesoMax;
}

int Carrinha::getCusto() const {
    return custo;
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

bool Carrinha::operator<(const Carrinha &rhs) const {
    if (volMax < rhs.volMax)
        return true;
    if (rhs.volMax < volMax)
        return false;
    if (pesoMax < rhs.pesoMax)
        return true;
    if (rhs.pesoMax < pesoMax)
        return false;
    return custo < rhs.custo;
}

bool Carrinha::operator>(const Carrinha &rhs) const {
    return rhs < *this;
}

bool Carrinha::operator<=(const Carrinha &rhs) const {
    return !(rhs < *this);
}

bool Carrinha::operator>=(const Carrinha &rhs) const {
    return !(*this < rhs);
}


