//
// Created by alois on 8/9/26.
//

#include "Funciones.hpp"

void abrir_archivo_entrada(const char * file_name, ifstream & input) {
    input.open(file_name, ios::in);
    if (not input.is_open()) {
        cout << "Error al abrir el archivo de entrada." << endl;
        exit(1);
    }
}

int leer_int(ifstream &input) {
    int dato;
    input>>dato;
    input.get();
    return dato;
}

int leer_fecha_hora(ifstream & input, int i) {
    int a,b,c;
    input>>a;
    if (input.eof()) return -1;
    input.get();
    b = leer_int(input);
    c = leer_int(input);
    return (a+b*100+c*10000)*(i==1) + (a*3600+b*60+c)*(i==2);
}

void incrementar_espacios(int *&fechas, int ***&datos_enteros, double ***&datos_de_punto_flotante, char ****&datos_de_texto,
                          int &n_datos, int &capacidad, int *&capacidades, int *&m_datos) {

    capacidad += INCREMENTO;

    if (fechas == nullptr) {
        fechas = new int [capacidad]{};
        datos_enteros = new int **[capacidad]{};
        datos_de_punto_flotante = new double **[capacidad]{};
        datos_de_texto = new char ***[capacidad]{};
        capacidades = new int [capacidad]{};
        m_datos = new int[capacidad]{};
        //n_datos = 1;
    } else {
        int *aux_f = new int[capacidad]{};
        int ***aux_de = new int **[capacidad]{};
        double ***aux_dpf = new double **[capacidad]{};
        char ****aux_dt = new char ***[capacidad]{};
        int *aux_cap = new int [capacidad]{};
        int *aux_m = new int [capacidad]{};

        for (int i = 0; i < n_datos; i++) {
            aux_f[i] = fechas[i];
            aux_de[i] = datos_enteros[i];
            aux_dpf[i] = datos_de_punto_flotante[i];
            aux_dt[i] = datos_de_texto[i];
            aux_cap[i] = capacidades[i];
            aux_m[i] = m_datos[i];
        }

        //eliminar punteros
        delete [] fechas;
        for (int i = 0; datos_enteros[i]; i++) {
            delete [] datos_enteros[i];
            delete [] datos_de_punto_flotante[i];
            delete [] datos_de_texto[i];
        }
        delete [] datos_enteros;
        delete [] datos_de_punto_flotante;
        delete [] datos_de_texto;

        fechas = aux_f;
        datos_enteros = aux_de;
        datos_de_punto_flotante = aux_dpf;
        datos_de_texto = aux_dt;
        capacidades = aux_cap;
        m_datos = aux_m;
    }
}

char * asignar_cadena(char * buffer) {
    char *cadena;
    cadena = new char[strlen(buffer)+1];
    strcpy(cadena, buffer);
    return cadena;
}

char * leer_cadena( ifstream &input, char del) {
    char buffer[MAX_CAD]{};
    input.getline(buffer, MAX_CAD, del);
    return asignar_cadena(buffer);
}

double leer_double( ifstream & input) {
    double dato;
    input >> dato;
    input.get();
    return dato;
}

void leer_datos(int *&datos_ent, double *&datos_dou, char **&datos_cad, ifstream & input) {
    //864-13-9865,S Valadez,03:54:00,36.8,121,99,05:33:10,Ginecologia
    datos_ent = new int [5]{};
    datos_dou = new double [2]{};
    datos_cad = new char *[3]{};

    datos_cad[0] = leer_cadena(input, ',');
    datos_cad[1] = leer_cadena(input, ',');
    datos_ent[0] = leer_fecha_hora(input, 2);
    datos_dou[0] = leer_double(input);
    datos_ent[2] = leer_int(input);
    datos_ent[3] = leer_int(input);
    datos_ent[1] = leer_fecha_hora(input, 2);
    datos_cad[2] = leer_cadena(input, '\r');
    datos_dou[1] = 0;
    datos_ent[4] = datos_ent[1] - datos_ent[0];
}

void incrementar_espacios_2(int **&datos_entero, double **&datos_doubles, char ***&datos_cadenas, int &capacidades, int &m_datos) {
    capacidades += INCREMENTO;

    if (datos_entero==nullptr) {
        datos_entero = new int *[capacidades]{};
        datos_doubles = new double *[capacidades]{};
        datos_cadenas = new char **[capacidades]{};
    }
}

void agregar_datos(int **&datos_entero, double **&datos_doubles, char ***&datos_cadenas,
                   int *&buffer_ent, double *&buffer_double, char **&buffer_cad, int &capacidades, int &m_datos) {
    if (m_datos==capacidades) incrementar_espacios_2(datos_entero, datos_doubles, datos_cadenas,capacidades,m_datos);


    m_datos++;
}

void insertar_ordenado(int fecha_leida, int *&fechas, int ***&datos_enteros, char ****&datos_de_texto, double ***&datos_de_punto_flotante,
                       int n_datos, int *&capacidades, int *&m_datos, ifstream & input) {
    int i=n_datos-1;

    while (i>=0 and fechas[i]>fecha_leida) {
        fechas[i+1]=fechas[i];
        **datos_enteros[i+1]=**datos_enteros[i];
        **datos_de_punto_flotante[i+1]=**datos_de_punto_flotante[i];
        ***datos_de_texto[i+1]=***datos_de_texto[i];
        capacidades[i+1] = capacidades[i];
        m_datos[i+1] = m_datos[i];
        i--;
    }
    fechas[i+1]=fecha_leida;
    capacidades[i+1]=0;
    m_datos[i+1]=0;
    char **buffer_cad; int *buffer_ent; double *buffer_dou;
    leer_datos(buffer_ent,buffer_dou,buffer_cad,input);
    agregar_datos(datos_enteros[i+1], datos_de_punto_flotante[i+1], datos_de_texto[i+1],
                  buffer_ent, buffer_dou, buffer_cad, capacidades[i+1], m_datos[i+1]);
}

void cargar_informacion(const char *file_name, int *&fechas, int ***&datos_enteros, char ****&datos_de_texto,
                        double ***&datos_de_punto_flotante) {
    ifstream input;
    abrir_archivo_entrada(file_name, input);

    int fecha_leida, capacidad=0, n_datos=0, *capacidades, *m_datos;
    while (true) {
        fecha_leida = leer_fecha_hora(input, 1);
        if (fecha_leida == -1 or input.eof()) break;

        if (n_datos==capacidad) incrementar_espacios(fechas, datos_enteros, datos_de_punto_flotante,datos_de_texto,
                                                     n_datos, capacidad, capacidades, m_datos);
        insertar_ordenado(fecha_leida, fechas, datos_enteros, datos_de_texto, datos_de_punto_flotante,
                          n_datos, capacidades, m_datos, input);

        n_datos++;
    }
}
