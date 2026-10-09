//
// Created by User on 8/10/2026.
//

#ifndef INC_2025_2_STREAMERS_HPP
#define INC_2025_2_STREAMERS_HPP
#include "Utils.hpp"
class Streamer {
private:
        char *cuenta;
        long long tiempo_total;
        double promedio_spectadores;
        int n_seguidores;
        char *categoria;

public:
        void get_cuenta(char *ptr_cad) const;
        void set_cuenta(char * const cuenta);
        long long get_tiempo_total() const;
        void set_tiempo_total(const long long tiempo_total);
        double get_promedio_spectadores() const;
        void set_promedio_spectadores(const double promedio_spectadores);
        int get_n_seguidores() const;
        void set_n_seguidores(const int n_seguidores);
        void get_categoria(char *ptr_cad) const;
        void set_categoria(char * const categoria);

        Streamer();
        Streamer(char * const cuenta, const long long tiempo_total, const double promedio_spectadores,
                const int n_seguidores, char * const categoria);
        ~Streamer();

        void leer_streamer(ifstream &input);
        void mostrar_streamer_arch(ofstream &output);
        void mostrar_streamer_consola();
        void copiar(const class Streamer &s);

};
#endif //INC_2025_2_STREAMERS_HPP
