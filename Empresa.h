#ifndef DA_T1_G119_EMPRESA_H
#define DA_T1_G119_EMPRESA_H

#include "Encomenda.h"
#include "Carrinha.h"
#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <queue>
#include <map>

using namespace std;

class Empresa {
private:
    vector<Carrinha> carrinhas;
    vector<Encomenda> encomendas;
public:
    //! \brief Construtor simples
    Empresa();
    //! \brief Adiciona Carrinhas
    //! Lê as carrinhas de um ficheiro e adiciona a um vector
    //! \param file ficheiro que contêm as carrinhas e a sua informação
    void addCarrinhas(string file);
    //! \brief Adiciona Encomendas
    //! Lẽ as encomendas de um ficheiro e adiciona a um vector
    //! \param file ficheiro que contêm as encomendas e a sua informação
    void addEncomendas(string file);
    //! \brief Ordena as Encomendas por menor espaço
    //! Espaço = Peso * Volume
    //! \return Fila ordenada por ordem crescente de espaço
    queue<Encomenda> ordenarEncomendasPorEspaco();
    //! \brief Ordena as Carrinhas por maior capacidade
    //! Capacidade = Peso * Volume
    //! \return Vector ordenado por ordem decrescente de capacidade
    vector<Carrinha> ordenarCarrinhasPorCapacidade();
    //! \brief Ordena as Encomendas por maior recompensa de transporte
    //! Recompensa de Transporte = (Peso * Volume) / Recompensa
    //! \return Fila ordenada por ordem crescente de recompensa de transporte
    queue<Encomenda> ordenarEncomendasPorRecompensa();
    //! \brief Ordena as Carrinhas por menor custo de transporte
    //! Custo de Transporte = (PesoMax * VolumeMax) / Custo
    //! \return Vector ordenado por ordem decrescente de custo de transporte
    vector<Carrinha> ordenarCarrinhasPorCusto();
    //! \brief Ordena as encomendas por menor duração
    //! \return Fila ordenada por ordem crescente de duração
    queue<Encomenda> ordenarEncomendasPorDuracao();
    //! \brief Otimiza o numero de entregas pelo menor número de estafetas
    void otimizarNumeroEstafetas();
    //! \brief Otimiza o lucro que a empresa possa ter
    void otimizarLucro();
    //! \brief Otimiza o número de entregas expresso feitas em 8 horas
    void otimizarEntregasExpresso();
};

#endif //DA_T1_G119_EMPRESA_H
