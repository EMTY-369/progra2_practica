//
// Created by User on 19/11/2026.
//

#include "SistemaDeAtencion.hpp"

void SistemaDeAtencion::cargarPacientes(const string &file_name) {
    ifstream input;
    Utils::abrir_archivo(input, file_name);

    while (true) {
        class Paciente p;
        input >> p;
        if (input.eof()) break;
        pacientes.push_back(p);
    }
    sort(pacientes.begin(), pacientes.end());
}

void SistemaDeAtencion::cargarMedicos(const string &file_name) {
    ifstream input;
    Utils::abrir_archivo(input, file_name);

    while (true) {
        string especialidad;
        getline(input, especialidad, ',');
        if (input.eof()) break;
        while (true) {
            class Medico m;
            input >> m;
            m.set_especialidad_nombre(especialidad);
            medicos.push_back(m);
            if (input.get() == '\n') break;
        }
    }
    medicos.sort();
}

void SistemaDeAtencion::cargarTriajes(const string &file_name) {
    ifstream input;
    Utils::abrir_archivo(input, file_name);

    while (true) {
        class Triaje t;
        input >> t;
        if (input.eof()) break;
        triajes.insert({t.get_codigo_triaje(), t});
    }
}

void SistemaDeAtencion::cargarAtenciones(const string &file_name) {
    ifstream input;
    Utils::abrir_archivo(input, file_name);

    while (true) {
        int dd, mm, aa;
        char c;
        input >> dd;
        if (input.eof()) break;
        input >> c >> mm >> c >> aa;
        while (input.get() != '\n'){
            class Atencion a;
            input >> a;
            a.set_fecha(dd+mm*100+aa*10000);
            atenciones.push_back(a);
        }
    }
    atenciones.sort();
}

void SistemaDeAtencion::llenarAtenciones() {
    auto it = atenciones.begin();
    for (int i = 0; i < atenciones.size(); i++) {
        it->calcularDuracion();
        it->set_triaje(triajes.at(it->get_codigo_triaje()));
        ++it;
    }
}

double SistemaDeAtencion::buscarTarifa(int cod) {
    auto it = medicos.begin();
    for (int i = 0; i < medicos.size(); i++) {
        if (cod == it->get_codigo()) return it->get_tarifa();
        ++it;
    }
    return 0;
}

void SistemaDeAtencion::llenarAtencionesDePacientes() {
    auto it = atenciones.begin();
    for (int i = 0; i < atenciones.size(); i++) {
        for (int j = 0; j < pacientes.size(); j++) {
            if (it->get_codigo_paciente() == pacientes.at(j).get_codigo()) {
                pacientes.at(j).guardarAtencion(*it, buscarTarifa(it->get_codigo_medico()));
                break;
            }
        }
        ++it;
    }
}

void SistemaDeAtencion::llenarAtencionesDeMedicos() {
    auto it = atenciones.begin();
    for (int i = 0; i < atenciones.size(); i++) {
        auto it_med = medicos.begin();
        for (int j = 0; j < medicos.size(); j++) {
            if (it->get_codigo_medico() == it_med->get_codigo()) {
                it_med->guardarAtencion(*it);
                break;
            }
            ++it_med;
        }
        ++it;
    }
}

void SistemaDeAtencion::reporteDeAtencionesPorPaciente(const string &file_name) {
    ofstream output;
    Utils::abrir_archivo(output, file_name);

    output<<fixed;
    output.precision(2);
    Utils::imprimir_linea(ANCHO, '=', output);
    output<<setw((ANCHO+24)/2)<<"ATENCIONES POR PACIENTES"<<endl;

    for (int i = 0; i < pacientes.size(); i++) {
        output << pacientes.at(i);
    }
    Utils::imprimir_linea(ANCHO, '=', output);
    output.close();
}

void SistemaDeAtencion::reporteDeAtencionesPorMedico(const string &file_name) {
    ofstream output;
    Utils::abrir_archivo(output, file_name);

    output<<fixed;
    output.precision(2);
    Utils::imprimir_linea(ANCHO, '=', output);
    output<<setw((ANCHO+21)/2)<<"ATENCIONES POR MEDICO"<<endl;

    auto it = medicos.begin();
    for (int i = 0; i < medicos.size(); i++) {
        output << *it;
        ++it;
    }
    Utils::imprimir_linea(ANCHO, '=', output);
    output.close();
}

SistemaDeAtencion::~SistemaDeAtencion() {
    atenciones.clear();
    pacientes.clear();
    triajes.clear();
    medicos.clear();
}
