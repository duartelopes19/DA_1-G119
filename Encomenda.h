#ifndef DA_T1_G119_ENCOMENDA_H
#define DA_T1_G119_ENCOMENDA_H

class Encomenda {
private:
    int idm;
    int idvol;
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
    Encomenda(int idm, int idvol, int volume, int peso, int recompensa, int duracao);
    //! \brief Getter simples do id manifesto
    //! \return id da manifesto da carrinha
    int getIdm() const;
    //! \brief Setter simples do manifesto
    //! \param idm id manifesto a substituir
    void setIdm(int idm);
    //! \brief Getter simples do id do volume
    //! \return id do volume da encomenda
    int getIdvol() const;
    //! \brief Setter simples do id do volume
    //! \param id do volume da encomenda
    void setIdvol(int idvol);
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
