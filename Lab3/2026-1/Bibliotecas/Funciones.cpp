//
// Created by User on 16/09/2026.
//

#include "Funciones.hpp"

void abrir_archivo_escritura(const char * ile_name, ofstream &output) {
    output.open(ile_name, ios::out);
    if (not output.is_open()) {
        cout << "Error al abrir el archivo escritura"<<endl;
        exit(1);
    }
}

void imprimir_linea(int n, char c, ofstream & output) {
    for (int i = 0; i<n; i++) output.put(c);
    output.put('\n');
}

void imprimir_titulo( ofstream & output) {
    imprimir_linea(ANDHO, '=', output);
    output<<setw((32+ANDHO)/2)<<"REPORTE DEL SISTEMA DE URGENCIAS"<<endl;
    imprimir_linea(ANDHO, '=', output);
    output<<endl;
    imprimir_linea(ANDHO, '-', output);
    output<<left<<setw(15)<<" ID"<<setw(25)<<"NOMBRE"<<setw(15)<<"EDAD"<<setw(15)<<"GENERO"<<setw(15)<<"VISITAS"<<right<<setw(15)<<"TOTAL (S/.)"<<endl;
    imprimir_linea(ANDHO, '-', output);
}

void imprimir_paciente(void *paciente, ofstream & output) {
    void **datos_paciente = (void**) paciente, **arr_visitas = (void**) datos_paciente[VISITAS];
    int j;
    for (j=0; arr_visitas[j]; j++);
    int *ptr_id = (int *)datos_paciente[ID], *ptr_edad = (int *)datos_paciente[EDAD];
    char *ptr_nombre = (char *)datos_paciente[NOMBRE], *ptr_genero = (char *)datos_paciente[GENERO];
    double *ptr_cost_total = (double *)datos_paciente[COSTOTOTAL];

    output<<left<<setw(15)<<*ptr_id<<setw(25)<<ptr_nombre<<setw(15)<<*ptr_edad
          <<setw(15)<<*ptr_genero<<setw(15)<<j<<right<<setw(15)<<*ptr_cost_total<<endl;
}

void generar_reporte(const char *file_name, void *pacientes) {
    ofstream output;
    abrir_archivo_escritura(file_name, output);
    output<<fixed;
    output.precision(2);
    void **arr_pacientes = (void **) pacientes;
    imprimir_titulo(output);
    for (int i = 0; arr_pacientes[i]; i++) {
        imprimir_paciente(arr_pacientes[i], output);
    }

}

double leer_double(ifstream & input) {
    double dato;
    input>>dato;
    input.get();
    return dato;
}

void leer_visita(void *&visita, int &cod_pac, ifstream & input) {
    char buffer[MAX_CAD]{}, *hora;
    input.getline(buffer, MAX_CAD, ',');
    if (input.eof()) return;
    hora = leer_cadena(input, ',');
    cod_pac = leer_int(input);
    double *costo = new double;
    *costo = leer_double(input);

    void **datos_visita = new void *[3]{};
    datos_visita[FECHA] = asignar_cadena(buffer);
    datos_visita[HORA] = hora;
    datos_visita[COSTO] = costo;

    visita = datos_visita;
}

int buscar_paciente(int cod_pac, void **pacientes) {
    for (int i = 0; pacientes[i]; i++) {
        void **datos_paciente = (void**) pacientes[i];
        if (cod_pac == *(int*)datos_paciente[ID]) return i;
    }
    return NO_ENCONTRADO;
}

void incrementar_capacidad(void *&visitas, int &n_visitas, int &capacidad) {
    void **arr_visitas = (void**) visitas;
    capacidad += INCREMENTO;
    if (arr_visitas == nullptr) {
        arr_visitas = new void *[capacidad]{};
        n_visitas = 1;
    } else {
        void **aux_visitas = new void *[capacidad]{};
        for (int i = 0; i<n_visitas; i++) aux_visitas[i] = arr_visitas[i];
        delete [] arr_visitas;
        arr_visitas = aux_visitas;
    }
    visitas = arr_visitas;
}

void agregar_visita(void *paciente, int &n_visitas, int &capacidad, void *visita) {
    void **datos_paciente = (void**) paciente, **datos_visit = (void**) visita;
    if (n_visitas == capacidad) incrementar_capacidad(datos_paciente[VISITAS], n_visitas, capacidad);
    void **arr_visitas = (void**) datos_paciente[VISITAS];
    arr_visitas[n_visitas-1] = visita;
    *(double *)datos_paciente[COSTOTOTAL] += *(double *) datos_visit[COSTO];
    n_visitas++;
}

void cargar_visitas(const char *file_name, void *pacientes) {
    ifstream input;
    abrir_archivo_lectura(file_name, input);
    void **arr_pacientes = (void **)pacientes, *visita;
    int n_visitas[90]{}, capacidades[90]{}, cod_pac;
    while (true) {
        leer_visita(visita, cod_pac, input);
        if (input.eof()) break;
        int pos = buscar_paciente(cod_pac, arr_pacientes);
        if (pos == NO_ENCONTRADO) {
            input.ignore(200,'\n');
            continue;
        }
        agregar_visita(arr_pacientes[pos], n_visitas[pos], capacidades[pos], visita);
    }
}

void abrir_archivo_lectura(const char *file_name, ifstream &input) {
    input.open(file_name, ios::in);
    if (!input.is_open()) {
        cout << "Error al abrir el archivo lectura" << endl;
        exit(1);
    }
}

int leer_int( ifstream & input) {
    int dato;
    input>>dato;
    input.get();
    return dato;
}

char * asignar_cadena(char * buffer) {
    char *cadena;
    cadena = new char[strlen(buffer)+1];
    strcpy(cadena, buffer);
    return cadena;
}

char * leer_cadena(ifstream & input, char del) {
    char buffer[MAX_CAD]{};
    input.getline(buffer, MAX_CAD, del);
    return asignar_cadena(buffer);
}

char leer_char( ifstream & input) {
    char dato;
    input>>dato;
    input.get();
    return dato;
}

void * leer_datos_paciente( ifstream & input) {
    //30001001,H. Glasspool,69,M
    int *ptr_id = new int, *ptr_edad = new int;
    char *nombre, *genero = new char;
    input>>*ptr_id;
    if (input.eof()) return nullptr;
    input.get();
    nombre = leer_cadena(input, ',');
    *ptr_edad = leer_int(input);
    *genero = leer_char(input);

    void **arr_datos = new void *[6]{};
    arr_datos[EDAD] = ptr_edad;
    arr_datos[ID] = ptr_id;
    arr_datos[GENERO] = genero;
    arr_datos[NOMBRE] = nombre;
    arr_datos[VISITAS] = nullptr;
    double *costo = new double;
    *costo = 0.0;
    arr_datos[COSTOTOTAL] = costo;
    return arr_datos;
}


void incrementar_tamanio(void **&arreglo_parcientes, int &n_pacientes, int &capacidad) {
    capacidad += INCREMENTO;
    if (arreglo_parcientes ==  nullptr) {
        arreglo_parcientes = new void *[capacidad]{};
        n_pacientes = 1;
    } else {
        void **aux_arr = new void *[capacidad]{};
        for (int i = 0; i < n_pacientes; i++) aux_arr[i] = arreglo_parcientes[i];
        delete [] arreglo_parcientes;
        arreglo_parcientes = aux_arr;
    }
}

void cargar_pacientes(const char *file_name, void *&pacientes) {
    ifstream input;
    abrir_archivo_lectura(file_name, input);
    int n_pacientes=0, capacidad=0;
    void **arreglo_parcientes = nullptr, *paciente;
    while (true) {
        paciente = leer_datos_paciente(input);
        if (input.eof()) break;

        if (n_pacientes == capacidad) incrementar_tamanio(arreglo_parcientes, n_pacientes, capacidad);
        arreglo_parcientes[n_pacientes-1] = paciente;
        n_pacientes++;
    }
    pacientes = arreglo_parcientes;
}
