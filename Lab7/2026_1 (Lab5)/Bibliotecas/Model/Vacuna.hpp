//
// Created by User on 4/11/2026.
//

#ifndef INC_2026_1__LAB5__VACUNA_HPP
#define INC_2026_1__LAB5__VACUNA_HPP
#include "Cita.hpp"

class Vacuna : public Cita {
public:
    int get_dosis() const;
    void set_dosis(const int dosis);
    int get_meses() const;
    void set_meses(const int meses);

    void leer(ifstream &input);
    void imprimir(ofstream &output);

    Vacuna();
    Vacuna(const class Vacuna &origin);
    ~Vacuna()=default;

private:
    int dosis;
    int meses;
};


#endif //INC_2026_1__LAB5__VACUNA_HPP
