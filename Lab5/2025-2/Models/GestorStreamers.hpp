//
// Created by User on 8/10/2026.
//

#ifndef INC_2025_2_GESTORSTREAMERS_HPP
#define INC_2025_2_GESTORSTREAMERS_HPP
#include "Streamer.hpp"

class GestorStreamers {
private:
        class Streamer *data;
        class Streamer *dataVista;
        int cantidad_datos;
        int cantidad_datos_vista;

public:
        class Streamer * get_data() const;
        void set_data(class Streamer * const data);
        class Streamer * get_data_vista() const;
        void set_data_vista(class Streamer * const data_vista);
        int get_cantidad_datos() const;
        void set_cantidad_datos(const int cantidad_datos);
        int get_cantidad_datos_vista() const;
        void set_cantidad_datos_vista(const int cantidad_datos_vista);

        GestorStreamers();
        ~GestorStreamers();

        void cargar_datos(const char *file_name);
        void mostrar_menu();
        char escoger_opciones_menu();
        void crear_reporte(char opcion);
        char escoger_op_reporte();
        void copiar_datos();
        void cortar_datos(int capacidad);

};

int comparar_seguidores(const void *a, const void *b);
int comparar_tiempo_total(const void *a, const void *b);
int compara_catg_prom_espec(const void *a, const void *b);
int comparar_categorias(const void *a, const void *b);

#endif //INC_2025_2_GESTORSTREAMERS_HPP
