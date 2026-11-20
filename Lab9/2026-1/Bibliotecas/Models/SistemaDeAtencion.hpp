//
// Created by User on 19/11/2026.
//

#ifndef INC_2026_1_SISTEMADEATENCION_HPP
#define INC_2026_1_SISTEMADEATENCION_HPP
#include "Paciente.hpp"
#include "Medico.hpp"

class SistemaDeAtencion {
public:
    void cargarPacientes(const string &file_name);
    void cargarMedicos(const string &file_name);
    void cargarTriajes(const string &file_name);
    void cargarAtenciones(const string &file_name);
    void llenarAtenciones();
    double buscarTarifa(int cod);
    void llenarAtencionesDePacientes();
    void llenarAtencionesDeMedicos();
    void reporteDeAtencionesPorPaciente(const string &file_name);
    void reporteDeAtencionesPorMedico(const string &file_name);

    SistemaDeAtencion() = default;
    ~SistemaDeAtencion();
private:
    list<class Atencion>atenciones;
    map<string, class Triaje>triajes;
    vector<class Paciente>pacientes;
    list<class Medico> medicos;
};


#endif //INC_2026_1_SISTEMADEATENCION_HPP
