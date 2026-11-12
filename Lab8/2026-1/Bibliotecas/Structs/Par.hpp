//
// Created by User on 11/11/2026.
//

#ifndef INC_2026_1_PAR_HPP
#define INC_2026_1_PAR_HPP
#include "../Model/Atencion.hpp"

class Par {
public:
    friend class NodoListaDoble;

    class Atencion * get_value() const;
    void set_value(class Atencion *value);
    int get_llave() const;
    void set_llave(const int llave);
    void imprimir(ofstream & output);

    Par();
    ~Par();
private:
    int llave;
    class Atencion *value;
};


#endif //INC_2026_1_PAR_HPP
