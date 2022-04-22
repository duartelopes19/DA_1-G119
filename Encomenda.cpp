#include "Encomenda.h"

Encomenda::Encomenda(int idm, int idvol, int volume, int peso, int recompensa, int duracao) : idm(idm),idvol(idvol),volume(volume), peso(peso),
                     recompensa(recompensa), duracao(duracao) {}

int Encomenda::getIdm() const {
    return idm;
}

void Encomenda::setIdm(int idm) {
     Encomenda::idm = idm;
}

int Encomenda::getIdvol() const {
    return idvol;
}

void Encomenda::setIdvol(int idvol) {
     Encomenda::idvol = idvol;
}

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
