//
// Created by User on 12/11/2026.
//

#ifndef INC_2025_2_ADMINISTRARMETRICAS_HPP
#define INC_2025_2_ADMINISTRARMETRICAS_HPP
#include "../Structs/Lista.hpp"
#include "../Structs/ArbolABB.hpp"

class AdministrarMetricas {
public:
    class Metrica * rservar_memoria(const string & tipo);
    void cargarArchivo(const string &file_name);
    void generarReporte(const string &file_name);
    void eliminarNodos();
    void eliminarLista();
    void generarReporteArbolABB(const string &file_name);
    void cargarArchivoArbolABB(const string &file_name);
    void eliminarNodosArbolABB();
    void eliminarArbolABB();

    AdministrarMetricas() = default;
    ~AdministrarMetricas() = default;
private:
    class Lista listaDeMetricas;
    class ArbolABB arbolDeMetricas;
};


#endif //INC_2025_2_ADMINISTRARMETRICAS_HPP
