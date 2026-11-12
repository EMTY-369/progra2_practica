//
// Created by User on 11/11/2026.
//

#include "ListaDoble.hpp"

void ListaDoble::insertar(int llave, class Atencion *atencion) {
    insertar_recursivo(cabeza, llave, atencion);
}

void ListaDoble::imprimir(ofstream &output, const string &fecha, int hora) {

    output<<setw((ANCHO+33)/2)<<"REPORTE DE ATENCIONES PRIORIZADAS"<<endl;
    output<<setw(65)<<"FECHA: "<<fecha<<"    HORA: "<<hora<<endl;

    imprimir_recursivo(cabeza, 0, output);
}

void ListaDoble::encabezadoEmergencia(ofstream &output) {

    output<<"EMERGENCIAS"<<endl;
    output<<setw(12)<<"PRIORIDAD"<<setw(10)<<"CODIGO"<<setw(30)<<"PACIENTE"<<setw(40)<<"DESCRIPCION"
          <<setw(10)<<"RCP?"<<setw(10)<<"NO PULSO"<<setw(20)<<"OBSERVACION"<<endl;
}

void ListaDoble::encabezadoUrgencia(ofstream &output) {
    output<<"URGENCIAS"<<endl;
    output<<setw(12)<<"PRIORIDAD"<<setw(10)<<"CODIGO"<<setw(30)<<"PACIENTE"<<setw(40)<<"DESCRIPCION"
          <<setw(30)<<"ZONA LESION"<<setw(10)<<"RX?"<<setw(20)<<"OBSERVACION"<<endl;
}

void ListaDoble::encabezadoNoUrgencia(ofstream &output) {
    output<<"NO URGENCIAS"<<endl;
    output<<setw(12)<<"PRIORIDAD"<<setw(10)<<"CODIGO"<<setw(30)<<"PACIENTE"<<setw(40)<<"DESCRIPCION"
          <<setw(30)<<"ESPECIALIDAD"<<setw(20)<<"PROGRAMADA?"<<endl;
}

ListaDoble::ListaDoble() {
    cabeza = nullptr;
}

ListaDoble::~ListaDoble() {
    destruir();
}

void ListaDoble::insertar_recursivo(class NodoListaDoble *recorrido, int llave, class Atencion *atencion) {
    if (recorrido!=nullptr and recorrido->siguiente!=nullptr and recorrido->siguiente->dato.get_llave() < llave) insertar_recursivo(recorrido->siguiente, llave, atencion);
    else {
        auto nuevo = new NodoListaDoble;
        nuevo->dato.set_llave(llave);
        nuevo->dato.set_value(atencion);

        if (cabeza == nullptr) cabeza = nuevo;
        else if (llave<= cabeza->dato.get_llave()){
            nuevo->siguiente = recorrido;
            recorrido->anterior = nuevo;
            cabeza = nuevo;
        } else {
            if (recorrido->siguiente!=nullptr) {
                nuevo->siguiente = recorrido->siguiente;
                recorrido->siguiente->anterior = nuevo;
            }
            recorrido->siguiente = nuevo;
            nuevo->anterior = recorrido;
        }
    }
}

void ListaDoble::imprimir_recursivo(class NodoListaDoble *recorrido, int tipo, ofstream &output) {
    if (recorrido == nullptr) return;
    int tipo_actual = recorrido->dato.get_llave()/10000;
    if (tipo != tipo_actual) {
        Utils::imprimir_linea(ANCHO, '=', output);
        if (tipo_actual == 1) encabezadoEmergencia(output);
        if (tipo_actual == 2) encabezadoUrgencia(output);
        if (tipo_actual == 3) encabezadoNoUrgencia(output);
    }

    recorrido->dato.imprimir(output);
    imprimir_recursivo(recorrido->siguiente, tipo_actual, output);
}

void ListaDoble::destruir() {
    cout <<"Destruyendo ListaDoble" << endl;
    class NodoListaDoble *recorrido = cabeza, *eliminar;
    if (recorrido==nullptr) return;
    while (recorrido->siguiente!=nullptr) {
        recorrido=recorrido->siguiente;
    }
    while (recorrido!=nullptr) {
        eliminar = recorrido;
        recorrido = recorrido->anterior;
        if (eliminar!=cabeza) {
            recorrido->siguiente = nullptr;
        } else cabeza = nullptr;

        delete eliminar;
    }
}
