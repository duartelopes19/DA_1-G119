//
// Created by User on 07/04/2022.
//

#include "Encomenda.h"

Encomenda::Encomenda(int volume, int peso, int recompensa, int duracao) : volume(volume), peso(peso),
                                                                          recompensa(recompensa), duracao(duracao) {}

int Encomenda::getVolume() const {
    return volume;
}

void Encomenda::setVolume(int volume) {
    Encomenda::volume = volume;
}

int Encomenda::getPeso() const {
    return peso;
}

void Encomenda::setPeso(int peso) {
    Encomenda::peso = peso;
}

int Encomenda::getRecompensa() const {
    return recompensa;
}

void Encomenda::setRecompensa(int recompensa) {
    Encomenda::recompensa = recompensa;
}

int Encomenda::getDuracao() const {
    return duracao;
}

void Encomenda::setDuracao(int duracao) {
    Encomenda::duracao = duracao;
}

bool Encomenda::operator<(const Encomenda &rhs) const {
    if (volume < rhs.volume)
        return true;
    if (rhs.volume < volume)
        return false;
    if (peso < rhs.peso)
        return true;
    if (rhs.peso < peso)
        return false;
    if (recompensa < rhs.recompensa)
        return true;
    if (rhs.recompensa < recompensa)
        return false;
    return duracao < rhs.duracao;
}

bool Encomenda::operator>(const Encomenda &rhs) const {
    return rhs < *this;
}

bool Encomenda::operator<=(const Encomenda &rhs) const {
    return !(rhs < *this);
}

bool Encomenda::operator>=(const Encomenda &rhs) const {
    return !(*this < rhs);
}
