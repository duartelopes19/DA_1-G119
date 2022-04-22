#ifndef DA_T1_G119_CARRINHA_H
#define DA_T1_G119_CARRINHA_H

class Carrinha {
private:
    int id;
    int volMax;
    int pesoMax;
    int custo;
public:
    //! \brief Construtor simples
    //! \param volMax Volume máximo da carrinha
    //! \param pesoMax Peso máximo da carrinha
    //! \param custo Custo de viagem da carrinha
    Carrinha(int id, int volMax, int pesoMax, int custo);
    //! \brief Getter simples do id
    //! \return da carrinha
    int getIdCar() const;
    //! \brief Getter simples do Volume
    //! \return Volume máximo da carrinha
    int getVolMax() const;
    //! \brief Getter simples do Peso
    //! \return Peso máximo da carrinha
    int getPesoMax() const;
    //! \brief Getter simples do Custo
    //! \return Custo de viagem da carrinha
    int getCusto() const;
    //! \brief Setter simples do Volume
    //! \param volMax Volume a substituir
    void setIdCar(int id);
    //! \brief Setter simples do Volume
    //! \param volMax Volume a substituir
    void setVolMax(int volMax);
    //! \brief Setter simples do Peso
    //! \param pesoMax Peso a substituir
    void setPesoMax(int pesoMax);
    //! \brief Setter simples do Custo
    //! \param custo Custo a substituir
    void setCusto(int custo);
};

#endif //DA_T1_G119_CARRINHA_H
