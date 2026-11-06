//
// Created by User on 4/11/2026.
//

#ifndef INC_2026_1__LAB5__CITA_HPP
#define INC_2026_1__LAB5__CITA_HPP
#include "Mascota.hpp"

class Cita {
public:
    int get_fecha() const;
    void set_fecha(const int fecha);
    int get_hora() const;
    void set_hora(const int hora);
    class Mascota get_amascota() const;
    void set_amascota(const class Mascota &amascota);

    void leer(ifstream &input);
    void imprimir(ofstream & output);

    Cita();
    Cita(const class Cita &other);
    ~Cita()=default;

private:
    int fecha;
    int hora;
    class Mascota Amascota;
};


#endif //INC_2026_1__LAB5__CITA_HPP
