//
// Created by User on 4/11/2026.
//

#ifndef INC_2026_1__LAB5__MASCOTA_HPP
#define INC_2026_1__LAB5__MASCOTA_HPP
#include "../Utils/Utils.hpp"

class Mascota {
public:
    int get_codigo() const;
    void set_codigo(const int codigo);
    string get_nombre() const;
    void set_nombre(const string &nombre);
    char get_tipo() const;
    void set_tipo(const char tipo);
    string get_raza() const;
    void set_raza(const string &raza);

    void leer(ifstream &input);
    void imprimir(ofstream & output);

    Mascota();
    Mascota(const class Mascota &origen);
    ~Mascota()=default;
private:
    int codigo;
    string nombre;
    char tipo;
    string raza;
};


#endif //INC_2026_1__LAB5__MASCOTA_HPP
