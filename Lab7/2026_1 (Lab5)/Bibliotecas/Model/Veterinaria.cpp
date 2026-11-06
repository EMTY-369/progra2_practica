//
// Created by User on 4/11/2026.
//

#include "Veterinaria.hpp"

Veterinaria::Veterinaria() {
    arrControl=nullptr;
    numdatControl=0;
    capaControl=0;
}

Veterinaria::~Veterinaria() {
    delete[] arrControl;
}

void Veterinaria::incrementar_espacios(int inc) {
    capaControl+=inc;
    if (arrControl == nullptr) arrControl=new class Control[capaControl];
    else {
        class Control *aux = new class Control[capaControl];
        for (int i=0;i<numdatControl;i++) aux[i]=arrControl[i];
        delete[] arrControl;
        arrControl=aux;
    }
}

void Veterinaria::cargarcitas(const string &file_name) {
    ifstream input;
    Utils::abrir_archivo(input, file_name);
    int n_vacunas=0, n_operaciones=0;
    while (true) {
        char c;
        input>>c;
        if (input.eof()) break;
        input.get();
        if (c=='C') {
            if (numdatControl == capaControl) incrementar_espacios(5);
            arrControl[numdatControl++].leer(input);
        } else if (c=='V') arrVacuna[n_vacunas++].leer(input);
        else if (c=='O') arrOperacion[n_operaciones++].leer(input);
        else input.ignore(200,'\n');
    }
    input.close();
}

void Veterinaria::imprimir_citas_control(ofstream &output) {
    output << "Citas de Control:" << endl;
    output<<left<<setw(14)<<" Fecha"<<setw(8)<<" Hora"<<setw(16)<<" Raza";
    output<<setw(20)<<" Nombre"<<setw(16)<<" Cod. Medico"<<"Monto"<<endl<<right;
    Utils::imprimir_linea(ANCHO, '-', output);

    double monto=0;
    for (int i=0; i<numdatControl; i++) {
        arrControl[i].imprimir(output);
        monto+=arrControl[i].get_costo();
    }
    output<<"Monto por Control: "<<monto<<endl;
}

void Veterinaria::imprimir_citas_vacuna(ofstream &output) {
    output << "Citas de Vacunas:" << endl;
    output<<left<<setw(14)<<" Fecha"<<setw(8)<<" Hora"<<setw(16)<<" Raza";
    output<<setw(20)<<" Nombre"<<setw(10)<<"Dosis"<<"Meses próxima Dosis"<<endl<<right;
    Utils::imprimir_linea(ANCHO, '-', output);

    int n=0;
    for (int i=0; arrVacuna[i].get_fecha()!=0; i++) {
        arrVacuna[i].imprimir(output);
        n++;
    }
    output<<"Numero de vacunas: "<<n<<endl;
}

void Veterinaria::imprimir_cita_operacion(ofstream &output) {
    output << "Citas de Operaciones:" << endl;
    output<<left<<setw(14)<<" Fecha"<<setw(8)<<" Hora"<<setw(16)<<" Raza";
    output<<setw(20)<<" Nombre"<<setw(14)<<"Anestesia"<<"Numero de medicos"<<endl<<right;
    Utils::imprimir_linea(ANCHO, '-', output);

    double total=0;
    for (int i=0; arrOperacion[i].get_fecha()!=0; i++) {
        arrOperacion[i].imprimir(output);
        total+=arrOperacion[i].get_total();
    }
    output<<"Total por operaciones: "<<total<<endl;
}

void Veterinaria::muestracitas(const string &file_name) {
    ofstream output;
    Utils::abrir_archivo(output, file_name);
    output << fixed;
    output.precision(2);

    imprimir_citas_control(output);
    output<<endl;
    imprimir_citas_vacuna(output);
    output<<endl;
    imprimir_cita_operacion(output);
    output.close();
}

void Veterinaria::ordenar() {
    class Control **aux = new Control *[numdatControl];
    for (int i=0; i<numdatControl; i++) aux[i] = &arrControl[i];

    qsort(aux, numdatControl, sizeof(Control *), Control::comparar);
    class Control *copia = new Control[numdatControl];
    for (int i=0; i<numdatControl; i++) copia[i]=*aux[i];
    delete [] arrControl;
    delete [] aux;
    arrControl=copia;
}
