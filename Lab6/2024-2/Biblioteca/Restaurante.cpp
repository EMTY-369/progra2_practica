//
// Created by alois on 29/10/26.
//

#include "Restaurante.hpp"

Restaurante::Restaurante() {
    clientes=nullptr;
    cantidadDeClientes=0;
    capacidadDeClientes=0;
    platos=nullptr;
    cantidadDePlatos=0;
    capacidadDePlatos=0;
}

Restaurante::~Restaurante() {
    delete[] clientes;
    delete[] platos;
}

void Restaurante::operator<(const char *file_name) {
    ifstream input;
    Utils::abrir_archivo(input, file_name);

    while (true) {
        class Cliente c;
        input>>c;
        if (input.eof()) break;
        if (cantidadDeClientes==capacidadDeClientes) incrementar_clientes(6);
        clientes[cantidadDeClientes++]=c;
    }
}

void Restaurante::operator<=(const char *file_name) {
    ifstream input;
    Utils::abrir_archivo(input, file_name);

    while (true) {
        class Plato p;
        input>>p;
        if (input.eof()) break;
        if (cantidadDePlatos==capacidadDePlatos) incrementar_platos(5);
        platos[cantidadDePlatos++]=p;
    }
}

void Restaurante::operator<<=(const char *file_name) {
    ifstream input;
    Utils::abrir_archivo(input, file_name);

    int num_pedido, dni;
    while (true) {
        input>>num_pedido;
        if (input.eof()) break;
        input.get();
        input>>dni;
        //input.get();
        int pos_cliente=buscar_cliente(dni);
        if (pos_cliente==-1) continue;
        leer_actualizar_info(pos_cliente, input);
    }
}

void Restaurante::operator>>(const char *file_name) {
    ofstream output;
    Utils::abrir_archivo(output, file_name);
    output<<fixed;
    output<<setprecision(2);

    output<<setw((ANCHO+18)/2)<<"RESTAURANTE 1INF25"<<endl;
    output<<setw((ANCHO+14)/2)<<"VENTAS DEL DIA"<<endl;
    Utils::imprimir_linea(ANCHO, '=', output);
    output<<setw((ANCHO+27)/2)<<"RELACION DE PLATOS VENDIDOS"<<endl;
    Utils::imprimir_linea(ANCHO, '-', output);
    imprimir_platos(output);
    Utils::imprimir_linea(ANCHO, '=', output);
    output<<setw((ANCHO+29)/2)<<"RELACION DE CLIENTES VENDIDOS"<<endl;
    Utils::imprimir_linea(ANCHO, '-', output);
    imprimir_clientes(output);
    Utils::imprimir_linea(ANCHO, '=', output);
}

void Restaurante::incrementar_clientes(int incremento) {
    capacidadDeClientes+=incremento;
    if (clientes==nullptr) clientes = new Cliente[capacidadDeClientes];
    else {
        auto *aux = new Cliente[capacidadDeClientes];
        for (int i=0;i<cantidadDeClientes;i++)
            aux[i]=clientes[i];
        delete [] clientes;
        clientes=aux;
    }
}

void Restaurante::incrementar_platos(int incremento) {
    capacidadDePlatos+=incremento;
    if (platos==nullptr) platos = new Plato[capacidadDePlatos];
    else {
        auto *aux = new Plato[capacidadDePlatos];
        for (int i=0;i<cantidadDePlatos;i++)
            aux[i]=platos[i];
        delete [] platos;
        platos=aux;
    }
}

int Restaurante::buscar_cliente(int dni) {

    for (int i=0;i<cantidadDeClientes;i++) {
        if (clientes[i].get_dni()==dni) return i;
    }
    return -1;
}

void Restaurante::leer_actualizar_info(int pos_cliente, ifstream &input) {

    while (input.get()!='\r') {
        //if (input.get()=='\r') break;
        char plato[9]{};
        input.getline(plato, 9, ',');
        int cant;
        input>>cant;
        int pos_plato=buscar_plato(plato);
        if (pos_plato==-1) continue;
        double gasto=platos[pos_plato].actualizar(cant, clientes[pos_cliente].get_descuento());
        clientes[pos_cliente].actualizar(gasto);
    }
}

int Restaurante::buscar_plato(char *plato) {

    for (int i=0;i<cantidadDePlatos;i++) {
        char codigo[9]{};
        platos[i].get_codigo(codigo);
        if (strcmp(codigo,plato)==0) return i;
    }
    return -1;
}

void Restaurante::imprimir_platos(ofstream &output) {
    output<<setw(120)<<"PLATOS"<<setw(40)<<"TOTAL"<<endl;
    output<<left<<setw(5)<<"No."<<setw(16)<<"CODIGO"<<setw(35)<<"NOMBRE";
    output<<setw(10)<<"PPRECIO"<<setw(14)<<"PREPARADOS"<<setw(14)<<"NO ATENDIDO";
    output<<setw(14)<<"ESPERADO"<<setw(14)<<"BRUTO"<<setw(14)<<"NETO"<<endl<<right;
    Utils::imprimir_linea(ANCHO, '-', output);

    for (int i=0;i<cantidadDePlatos;i++) {
        output<<setw(3)<<i+1<<")  ";
        output<<platos[i];
    }
}

void Restaurante::imprimir_clientes(ofstream &output) {
    output<<left<<setw(5)<<"No."<<setw(14)<<"DNI"<<setw(40)<<"NOMBRE";
    output<<setw(38)<<"DISTRITO"<<setw(14)<<"DESCUENTO"<<"TOTAL PAGADO"<<right<<endl;
    Utils::imprimir_linea(ANCHO, '-', output);

    for (int i=0;i<cantidadDeClientes;i++) {
        output<<setw(3)<<i+1<<")  ";
        output<<clientes[i];
    }
}
