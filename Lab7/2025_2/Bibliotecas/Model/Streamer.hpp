//
// Created by User on 5/11/2026.
//

#ifndef INC_2025_2_STREAMER_HPP
#define INC_2025_2_STREAMER_HPP
#include "MetricaBasica.hpp"
#include "MetricaEngagement.hpp"
#include "MetricaCalidad.hpp"

class Streamer {
public:
    int get_id() const;
    void set_id(const int id);
    string get_cuenta() const;
    void set_cuenta(const string &cuenta);
    int get_n_seguidores() const;
    void set_n_seguidores(const int n_seguidores);
    string get_categoria() const;
    void set_categoria(const string &categoria);

    void leer(ifstream &input);
    void imprimir(ofstream &output);

    Streamer();
    ~Streamer()=default;
private:
    int id;
    string cuenta;
    int n_seguidores;
    string categoria;
};


#endif //INC_2025_2_STREAMER_HPP
