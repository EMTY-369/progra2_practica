//
// Created by User on 12/11/2026.
//

#ifndef INC_2025_2_METRICA_HPP
#define INC_2025_2_METRICA_HPP
#include "../Utils/Utils.hpp"

class Metrica {
public:
    int get_id() const;
    void set_id(const int id);
    string get_descripcion() const;
    void set_descripcion(const string &descripcion);
    int get_fecha_calculo() const;
    void set_fecha_calculo(const int fecha_calculo);
    int get_fecha_expiracion() const;
    void set_fecha_expiracion(const int fecha_expiracion);
    bool is_estado() const;
    void set_estado(const bool estado);

    virtual void leer(ifstream &input);
    virtual int obtenerTipoMetrica() = 0;
    virtual void imprimir_encabezado(ofstream & output);
    virtual void imprimir(ofstream & output);

    Metrica();
    Metrica(const Metrica &other);
    virtual ~Metrica() = default;
private:
    int id;
    string descripcion;
    int fecha_calculo;
    int fecha_expiracion;
    bool estado;
};


#endif //INC_2025_2_METRICA_HPP
