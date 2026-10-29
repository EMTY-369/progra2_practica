//
// Created by alois on 28/10/26.
//

#ifndef INC_2026_1__LAB5__VETERINARIA_HPP
#define INC_2026_1__LAB5__VETERINARIA_HPP
#include "Mascota.hpp"

class Veterinaria {
private:
    Mascota *listaMascotas;
    int numMascotas;
public:
    Veterinaria();
    ~Veterinaria();

    void operator<=(const char *file_name);
    void operator<<=(const char *file_name);
    void operator<<(const char *file_name);

    int buscar_mascota(const char *nombre);
    void imprimir_encabezado(ofstream &output);
};


#endif //INC_2026_1__LAB5__VETERINARIA_HPP
