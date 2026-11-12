//
// Created by User on 11/11/2026.
//

#ifndef INC_2026_1__LAB7__ATENCION_HPP
#define INC_2026_1__LAB7__ATENCION_HPP
#include "../Utils/Utils.hpp"

class Atencion {
public:
    int get_codigo() const;
    void set_codigo(const int codigo);
    string get_paciend() const;
    void set_paciend(const string &paciend);
    string get_descripcion() const;
    void set_descripcion(const string &descripcion);
    int get_hora() const;
    void set_hora(const int hora);

    virtual int obtener_prioridad() = 0;
    virtual int obtener_llave() = 0;
    virtual Atencion *clonar() const = 0;
    virtual void leer(ifstream &input, int hora);
    virtual void imprimir(ofstream & output);

    Atencion();
    Atencion(const class Atencion &other);
    virtual ~Atencion() = default;
private:
    int codigo;
    string paciente;
    string descripcion;
    int hora;
};


#endif //INC_2026_1__LAB7__ATENCION_HPP
