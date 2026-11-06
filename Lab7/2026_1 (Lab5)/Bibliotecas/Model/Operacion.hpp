//
// Created by User on 4/11/2026.
//

#ifndef INC_2026_1__LAB5__OPERACION_HPP
#define INC_2026_1__LAB5__OPERACION_HPP
#include "Cita.hpp"

class Operacion : public Cita {
public:
    bool get_anestesiageneral() const;
    void set_anestesiageneral(const bool anestesiageneral);
    int get_nummedicos() const;
    void set_nummedicos(const int nummedicos);
    double get_total() const;
    void set_total(const double total);

    void leer(ifstream &input);
    void imprimir(ofstream &output);

    Operacion();
    Operacion(const class Operacion &origin);
    ~Operacion()=default;

private:
    bool anestesiageneral;
    int nummedicos;
    double total;
};


#endif //INC_2026_1__LAB5__OPERACION_HPP
