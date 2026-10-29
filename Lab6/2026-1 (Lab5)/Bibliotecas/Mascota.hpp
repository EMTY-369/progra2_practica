//
// Created by alois on 27/10/26.
//

#ifndef INC_2026_1__LAB5__MASCOTA_HPP
#define INC_2026_1__LAB5__MASCOTA_HPP
#include "VacunaAplicada.hpp"

class Mascota {
private:
    int dni;
    char *nombre;
    char *especie;
    int edad;
    double peso;
    char *colegiatura;
    class VacunaAplicada listaVacunas[20];
    int numVacunas;

public:

    Mascota();
    Mascota(const Mascota &other);
    ~Mascota();

    void operator=(const Mascota &other);
    void operator+=(class VacunaAplicada &v);
    bool operator~();

    int get_dni() const;
    void set_dni(const int dni);
    void get_nombre(char *nombre) const;
    void set_nombre(const char *nombre);
    void get_especie(char *especie) const;
    void set_especie(const char *especie);
    int get_edad() const;
    void set_edad(const int edad);
    double get_peso() const;
    void set_peso(const double peso);
    void get_colegiatura(char *colegiatura) const;
    void set_colegiatura(const char *colegiatura);
    int get_num_vacunas() const;
    void set_num_vacunas(const int num_vacunas);

    void leer(ifstream &input);

    void imprimir_vacunas( ofstream & output);
};

void operator>>(ifstream &input,class Mascota &m);
void operator<<(ofstream &output,const class Mascota &m);


#endif //INC_2026_1__LAB5__MASCOTA_HPP
