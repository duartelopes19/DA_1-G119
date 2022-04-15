#ifndef DA_T1_G119_ENCOMENDA_H
#define DA_T1_G119_ENCOMENDA_H

class Encomenda {
private:
    int volume;
    int peso;
    int recompensa;
    int duracao;
public:
    Encomenda(int volume, int peso, int recompensa, int duracao);
    int getVolume() const;
    void setVolume(int volume);
    int getPeso() const;
    void setPeso(int peso);
    int getRecompensa() const;
    void setRecompensa(int recompensa);
    int getDuracao() const;
    void setDuracao(int duracao);
};

#endif //DA_T1_G119_ENCOMENDA_H
