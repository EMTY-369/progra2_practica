//
// Created by User on 12/11/2026.
//

#ifndef INC_2025_2_ADMINISTRARMETRICAS_HPP
#define INC_2025_2_ADMINISTRARMETRICAS_HPP
#include "../Structs/Lista.hpp"

class AdministrarMetricas {
public:
    class Metrica * rservar_memoria(const string & tipo);
    void cargarArchivo(const string &file_name);
    void generarReporte(const string &file_name);
    void eliminarNodos();
    void eliminarLista();

    AdministrarMetricas() = default;
    ~AdministrarMetricas() = default;
private:
    class Lista listaDeMetricas;
};


#endif //INC_2025_2_ADMINISTRARMETRICAS_HPP
