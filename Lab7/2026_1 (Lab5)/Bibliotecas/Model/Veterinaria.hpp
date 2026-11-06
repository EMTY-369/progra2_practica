//
// Created by User on 4/11/2026.
//

#ifndef INC_2026_1__LAB5__VETERINARIA_HPP
#define INC_2026_1__LAB5__VETERINARIA_HPP
#include "Control.hpp"
#include "Operacion.hpp"
#include "Vacuna.hpp"

class Veterinaria {
public:
    Veterinaria();
    ~Veterinaria();

    void incrementar_espacios(int inc);
    void cargarcitas(const string &file_name);
    void imprimir_citas_control(ofstream & output);
    void imprimir_citas_vacuna(ofstream & output);
    void imprimir_cita_operacion(ofstream & output);
    void muestracitas(const string &file_name);

    void ordenar();

private:
    class Control *arrControl;
    class Vacuna arrVacuna[MAX_ELE];
    class Operacion arrOperacion[MAX_ELE];
    int numdatControl;
    int capaControl;
};


#endif //INC_2026_1__LAB5__VETERINARIA_HPP
