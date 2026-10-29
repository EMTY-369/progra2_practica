//
// Created by alois on 27/10/26.
//

#ifndef INC_2026_1__LAB5__VACUNAAPLICADA_HPP
#define INC_2026_1__LAB5__VACUNAAPLICADA_HPP
#include "Utils.hpp"

class VacunaAplicada {
private:
    char *nombre;
    int fecha;
    double dosis;
    char *colegiatura;
public:
    VacunaAplicada();
    VacunaAplicada(const VacunaAplicada &other);
    ~VacunaAplicada();

    void operator=(const VacunaAplicada &other);
    bool operator==(const VacunaAplicada &other);

    void get_nombre(char *nombre) const;
    void set_nombre(const char *nombre);
    int get_fecha() const;
    void set_fecha(const int fecha);
    double get_dosis() const;
    void set_dosis(const double dosis);
    void get_colegiatura(char *colegiatura) const;
    void set_colegiatura(const char *colegiatura);

    void leer(ifstream & input);
};

void operator>>(ifstream &input, class VacunaAplicada &v);
void operator<<(ofstream &output, const VacunaAplicada &v);

#endif //INC_2026_1__LAB5__VACUNAAPLICADA_HPP
