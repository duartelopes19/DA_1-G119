#ifndef DA_T1_G119_ENCOMENDA_H
#define DA_T1_G119_ENCOMENDA_H

class Encomenda {
private:
    int volume;
    int peso;
    int recompensa;
    int duracao;
public:
    //! \brief Construtor simples
    //! \param volume Volume da encomenda
    //! \param peso Peso da encomenda
    //! \param recompensa Recompensa pela entrega da encomenda
    //! \param duracao Duração da entrega
    Encomenda(int volume, int peso, int recompensa, int duracao);
    //! \brief Getter simples do Volume
    //! \return Volume da encomenda
    int getVolume() const;
    //! \brief Setter simples do Volume
    //! \param volume Volume a substituir
    void setVolume(int volume);
    //! \brief Getter simples do Peso
    //! \return Peso da encomenda
    int getPeso() const;
    //! \brief Setter simples do Peso
    //! \param peso Peso a substituir
    void setPeso(int peso);
    //! \brief Getter simples da Recompensa
    //! \return Recompensa por entrega da encomenda
    int getRecompensa() const;
    //! \brief Setter simples da Recompensa
    //! \param recompensa Recompensa a substituir
    void setRecompensa(int recompensa);
    //! \brief Getter simples da Duração
    //! \return Duraçaão da entrega da encomenda
    int getDuracao() const;
    //! \brief Setter simples da Duração
    //! \param duracao Duração a substituir
    void setDuracao(int duracao);
};

#endif //DA_T1_G119_ENCOMENDA_H
