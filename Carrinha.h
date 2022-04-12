//
// Created by User on 07/04/2022.
//

#ifndef DA_T1_G119_CARRINHA_H
#define DA_T1_G119_CARRINHA_H


#include <ostream>

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
    bool operator<(const Carrinha &rhs) const;
    bool operator>(const Carrinha &rhs) const;
    bool operator<=(const Carrinha &rhs) const;
    bool operator>=(const Carrinha &rhs) const;
};


#endif //DA_T1_G119_CARRINHA_H
