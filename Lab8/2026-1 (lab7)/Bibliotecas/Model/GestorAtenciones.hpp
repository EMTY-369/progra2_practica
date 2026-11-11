//
// Created by User on 11/11/2026.
//

#ifndef INC_2026_1__LAB7__GESTORATENCIONES_HPP
#define INC_2026_1__LAB7__GESTORATENCIONES_HPP
#include "Emergencia.hpp"
#include "Urgencia.hpp"
#include "NoUrgencia.hpp"

class GestorAtenciones {
public:
    int get_cantidad_atenciones() const;
    void set_cantidad_atenciones(const int cantidad_atenciones);
    int get_capacidad() const;
    void set_capacidad(const int capacidad);

    void eliminar_profundo();
    void reservar_memoria();
    Atencion *reservar_memoria_atencion(char tipo);
    void agregar_atencion(class Atencion *atencion);
    void cargar_atenciones(const string &file_name, int hora);
    void procesar_dia(const string &fecha);

    GestorAtenciones();
    GestorAtenciones(const class GestorAtenciones &other);
    ~GestorAtenciones();
private:
    class Atencion **atenciones;
    int cantidad_atenciones;
    int capacidad;
};


#endif //INC_2026_1__LAB7__GESTORATENCIONES_HPP
