#ifndef DA_T1_G119_CARRINHA_H
#define DA_T1_G119_CARRINHA_H

class Carrinha {
private:
    int volMax;
    int pesoMax;
    int custo;
public:
    Carrinha(int volMax, int pesoMax, int custo);
    int getVolMax() const;
    int getPesoMax() const;
    int getCusto() const;
    void setVolMax(int volMax);
    void setPesoMax(int pesoMax);
    void setCusto(int custo);
};

#endif //DA_T1_G119_CARRINHA_H
