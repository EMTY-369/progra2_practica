//
// Created by alois on 28/10/26.
//

#include "MinisterioDeTransporte.hpp"

MinisterioDeTransporte::MinisterioDeTransporte() {
    infracciones = nullptr;
    numInf = 0;
    numEmp = 0;
}

MinisterioDeTransporte::~MinisterioDeTransporte() {
    delete[] infracciones;
}

void MinisterioDeTransporte::operator<(const char *file_name) {
    ifstream input;
    Utils::abrir_archivo(input, file_name);
    this->infracciones = new Infraccion[NUM_INF];

    while (true) {
        class Infraccion i;
        input>>i;
        if (input.eof()) break;
        infracciones[numInf++] = i;
    }
}

void MinisterioDeTransporte::operator<=(const char *file_name) {
    ifstream input;
    Utils::abrir_archivo(input, file_name);

    while (true) {
        class Empresa e;
        input>>e;
        if (input.eof()) break;
        empresas[numEmp++] = e;
        //cout<<empresas[numEmp-1].get_num_multas()<<endl;
    }
}

void MinisterioDeTransporte::operator<<=(const char *file_name) {
    ifstream input;
    Utils::abrir_archivo(input, file_name);

    while (true) {
        class Multa m;
        input>>m;
        if (input.eof()) break;
        int pos_i=buscar_infraccion(m.get_codigo_infraccion());
        if (pos_i==-1) continue;
        m.set_multa(infracciones[pos_i].get_multa());
        char placa[9]{};
        m.get_placa(placa);
        int pos_e=buscar_empresa(placa);
        if (pos_e==-1) continue;
        empresas[pos_e]+=m;
    }
}

void MinisterioDeTransporte::operator>>(const char *file_name) {
    ofstream output;
    Utils::abrir_archivo(output, file_name);

    output<<fixed;
    output<<setprecision(2);

    output<<setw((ANCHO+24)/2)<<"MINISTERIO DE TRANSPORTE"<<endl;
    Utils::imprimir_linea(ANCHO, '=', output);
    imprimir_infracciones(output);
    imprimir_empresas(output);
    Utils::imprimir_linea(ANCHO, '=', output);
}

int MinisterioDeTransporte::buscar_infraccion(int cod) {
    for (int i = 0; i < numInf; i++) {
        if (infracciones[i].get_codigo()==cod) return i;
    }
    return -1;
}

int MinisterioDeTransporte::buscar_empresa(const char *placa) {
    for (int i = 0; i < numEmp; i++) {
        int n = empresas[i].get_num_placas();
        for (int j=0; j<n; j++) {
            char placa2[9]{};
            empresas[i].get_placaI(placa2, j);
            if (strcmp(placa2, placa)==0) return i;
        }
    }
    return -1;
}

void MinisterioDeTransporte::imprimir_infracciones(ofstream &output) {
    output<<setw((ANCHO+21)/2)<<"TABLA DE INFRACCIONES"<<endl;
    Utils::imprimir_linea(ANCHO, '-', output);
    output<<left<<setw(6)<<""<<setw(10)<<"CODIGO"<<setw(10)<<"MULTA"<<setw(6)<<"";
    output<<setw(14)<<"GRAVEDAD"<<"DESCRIPCION"<<endl<<right;
    Utils::imprimir_linea(ANCHO, '-', output);

    for (int i = 0; i < numInf; i++) {
        output<<setw(6)<<"";
        output<<infracciones[i];
    }
    Utils::imprimir_linea(ANCHO, '=', output);
}

void MinisterioDeTransporte::imprimir_empresas(ofstream &output) {
    output<<setw((ANCHO+49)/2)<<"RELACION DE EMPRESAS CON INFRACCIONES DE TRANSITO"<<endl;
    Utils::imprimir_linea(ANCHO, '-', output);
    output<<left<<setw(6)<<""<<setw(14)<<"DNI"<<setw(50)<<"NOMBRE"<<"PLACAS DE SUS VEHICULOS"<<endl;
    Utils::imprimir_linea(ANCHO, '-', output);

    for (int i = 0; i < numEmp; i++) {
        output<<empresas[i];
    }
}
