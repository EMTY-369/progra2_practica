//
// Created by User on 12/11/2026.
//

#ifndef INC_2025_2_NODO_HPP
#define INC_2025_2_NODO_HPP
#include "../Model/MetricaBasica.hpp"
#include "../Model/MetricaEngagement.hpp"
#include "../Model/MetricaCalidad.hpp"

class Nodo {
public:
    friend class Lista;

    Nodo();
    Nodo(class Metrica *tipo,class Nodo *anterior,class  Nodo *siguiente);
    ~Nodo();
private:
    class Metrica *metrica;
    class Nodo *anterior;
    class Nodo *siguiente;
};


#endif //INC_2025_2_NODO_HPP
