//
// Created by User on 11/11/2026.
//

#ifndef INC_2026_1_LISTADOBLE_HPP
#define INC_2026_1_LISTADOBLE_HPP

#include "NodoListaDoble.hpp"

class ListaDoble {
public:
    void insertar(int llave, class Atencion *atencion);
    void imprimir(ofstream &output, const string &fecha, int hora);
    void encabezadoEmergencia(ofstream & output);
    void encabezadoUrgencia(ofstream & output);
    void encabezadoNoUrgencia(ofstream & output);

    ListaDoble();
    ~ListaDoble();
private:
    void insertar_recursivo(class NodoListaDoble *recorrido, int llave, class Atencion *atencion);
    void imprimir_recursivo(class NodoListaDoble *recorrido, int tipo, ofstream &output);
    void destruir();
    class NodoListaDoble *cabeza;
};


#endif //INC_2026_1_LISTADOBLE_HPP
