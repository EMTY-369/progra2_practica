//
// Created by User on 19/11/2026.
//

#ifndef INC_2026_1_HORA_HPP
#define INC_2026_1_HORA_HPP
#include "../Utils/Utils.hpp"

class Hora {
public:
    int get_hh() const;
    void set_hh(const int hh);
    int get_mm() const;
    void set_mm(const int mm);
    int get_ss() const;
    void set_ss(const int ss);
    int get_segundos() const;
    void set_segundos(const int segundos);
    void leer(ifstream & input);
    void imprimir(ofstream & output) const;

    Hora();
    ~Hora() = default;
private:
    int hh;
    int mm;
    int ss;
    int segundos;
};

void operator>>(ifstream &input,class Hora &hora);
void operator<<(ofstream &output,const class Hora &hora);

#endif //INC_2026_1_HORA_HPP
