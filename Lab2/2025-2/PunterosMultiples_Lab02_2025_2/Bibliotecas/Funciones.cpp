//
// Created by User on 10/09/2026.
//

#include "Funciones.hpp"

void abrir_archivo_salida(const char *file_name, ofstream &output) {
    output.open(file_name, ios::out);
    if (!output.is_open()) {
        cout << "Error al abrir archivo de salida "<<endl;
        exit(1);
    }
}

void imprimir_linea(int n, char c, ofstream & output) {
    for (int i=0; i<n; i++) output.put(c);
    output<<endl;
}

void imprimir_titulo(char ** categoria, ofstream &output) {
    int n=(int)strlen(categoria[1]);

    output<<"/";
    for (int i=0; i<(ANCHO-n-2)/2; i++) output.put('*');
    output<<categoria[1];
    for (int i=0; i<(ANCHO-n-2)/2; i++) output.put('*');
    output<<"/"<<endl;
    output<<left<<setw(30)<<"CUENTA"<<setw(25)<<"FECHA CREACION"<<setw(25)<<"FECHA ULT. STREAM."<<setw(15)<<"TIEMPO REP."
          <<setw(20)<<"CANT. SEGUID."<<"ETIQUETAS"<<endl<<right;
    imprimir_linea(ANCHO, '=', output);
}

void imprimir_streamer(char **&streamer, int *&fechas_promedio, long long *&tiempo_rep_seguidore, char ***&comentarios,
                      char ***&etiquetas, ofstream &output) {
    output<<left<<setw(30)<<streamer[0]<<setw(25)<<fechas_promedio[0]<<setw(25)<<fechas_promedio[1]
          <<setw(6)<<(double)tiempo_rep_seguidore[0]/(1000*24*3600.0)<<" (dias)"<<right<<setw(20)<<tiempo_rep_seguidore[1];


    output<<endl;
}

void imprimir_reporte(const char *file_name, char ***&categorias, char ***&streamers, int **&fechas_promedios,
                      long long **&tiempo_rep_seguidores, char ***&comentarios, char ***&etiquetas) {
    ofstream output;
    abrir_archivo_salida(file_name, output);
    output<<fixed;
    output<<setprecision(2);
    for (int i=0; categorias[i]; i++) {
        imprimir_titulo(categorias[i], output);
        char **lista_cat = categorias[i];
        for (int j=0; streamers[j]; j++) {
            char **lista_str = streamers[j];
            if (strcmp(lista_cat[0], lista_str[1]) == 0) {
                imprimir_streamer(streamers[j], fechas_promedios[j], tiempo_rep_seguidores[j], comentarios, etiquetas, output);
            }
        }
        output<<endl;
    }

}

void agregarMemoriaPorIncrementoComentarios(char ***&comentarios, int &n_com, int &capacidad) {
    capacidad += INCREMENTO;

    if (comentarios==nullptr) {
        comentarios = new char **[capacidad]{};
    } else {
        char ***aux_coment = new char **[capacidad]{};
        for (int i=0; i<n_com; i++) aux_coment[i] = comentarios[i];
        delete [] comentarios;
        comentarios = aux_coment;
    }
}

char ** cargar_lista_menciones(char *menciones) {
    char *buffer_menciones[MAX_MENCIONES]{}, nombre[20]{};
    int n=0, j=0;
    for (int i=0; i<strlen(menciones)+1; i++) {
        if (menciones[i]==' ' or menciones[i]=='\0') {
            buffer_menciones[n]=nombre;
            j=0;
            n++;
            continue;
        }
        nombre[j] = menciones[i];
        nombre[j+1] = '\0';
        j++;
    }
    char **lista = new char *[n+1]{};
    for (int i=0; i<n; i++) lista[i] = buffer_menciones[i];
    lista[n] = nullptr;
    return lista;
}

void recortar_comentarios(char ***&comentarios, int n_com) {
    char ***aux_comentarios = new char **[n_com+1]{};
    for (int i=0; i<n_com; i++) aux_comentarios[i] = comentarios[i];
    aux_comentarios[n_com] = nullptr;
    delete []comentarios;
    comentarios = aux_comentarios;
}

void cargar_comentarios(const char *file_name, char ***&comentarios, char ***&etiquetas) {
    ifstream input;
    abrir_archivo_entrada(file_name, input);
    int n_com=0, capacidad=0;
    char **buffer_etiquetas[MAX_ETIQUETAS]{};
    while (true) {
        char parte1[MAX_CAD]{}, parte2[MAX_CAD]{}, buffer_eti[50]{}, usuario[20]{};
        input.getline(usuario, 20, ',');
        if (input.eof()) break;
        input.getline(parte1, MAX_CAD, '[');
        input.getline(buffer_eti, 50, ']');
        input.getline(parte2, MAX_CAD, '\n');
        strcat(parte1, parte2);
        if (n_com>=capacidad-1) agregarMemoriaPorIncrementoComentarios(comentarios, n_com, capacidad);
        buffer_etiquetas[n_com] = cargar_lista_menciones(buffer_eti);
        n_com++;
    }
    recortar_comentarios(comentarios, n_com);
    etiquetas = new char **[n_com]{};
    for (int i=0; i<n_com; i++) etiquetas[i] = buffer_etiquetas[i];
}

void agregarMemoriaPorIncrementoStreamers(char ***&streamers, int **&fechas_promedios, long long **&tiempo_rep_seguidores,
                                          int &n_streamers, int &capacidad) {
    capacidad+=INCREMENTO;

    if (streamers==nullptr) {
        streamers = new char **[capacidad]{};
        fechas_promedios = new int *[capacidad]{};
        tiempo_rep_seguidores = new long long *[capacidad]{};
    } else {
        char ***aux_str = new char **[capacidad]{};
        int **aux_fe = new int *[capacidad]{};
        long long **aux_tiempo = new long long *[capacidad]{};

        for (int i=0; i<n_streamers; i++) {
            aux_str[i] = streamers[i];
            aux_fe[i] = fechas_promedios[i];
            aux_tiempo[i] = tiempo_rep_seguidores[i];
        }

        delete []streamers;
        delete []fechas_promedios;
        delete []tiempo_rep_seguidores;

        streamers = aux_str;
        fechas_promedios = aux_fe;
        tiempo_rep_seguidores = aux_tiempo;
    }
}

int leer_int( ifstream & input) {
    int dato;
    input>>dato;
    input.get();
    return dato;
}

int leer_fecha( ifstream &input) {
    int dia, mes, anio;
    dia = leer_int(input);
    mes = leer_int(input);
    anio = leer_int(input);
    return anio*10000+mes*100+dia;
}

long long leer_long( ifstream & input){
    long long dato;
    input>>dato;
    input.get();
    return dato;
}

void leer_guardar_datos(ifstream &input, char ***&streamers, int **&fechas_promedios, long long **&tiempo_rep_seguidores, int n_streamers, char
                        *buffer) {
    streamers[n_streamers] = new char *[2]{};
    char **lista_cad = streamers[n_streamers];
    fechas_promedios[n_streamers] = new int [3]{};
    int *lista_ent = fechas_promedios[n_streamers];
    tiempo_rep_seguidores[n_streamers] = new long long [2]{};
    long long *lista_long = tiempo_rep_seguidores[n_streamers];

    lista_cad[0] = asignar_cadena(buffer);
    lista_ent[0] = leer_fecha(input);
    lista_ent[1] = leer_fecha(input);
    lista_long[0] =leer_long(input);
    lista_ent[2] = leer_int(input);
    lista_long[1] = leer_long(input);
    lista_cad[1] = leer_cadena(input, '\n');
}

void recortar_streamers(int n_streamers, char ***&streamers, int **&fechas_promedios, long long **&tiempo_rep_seguidores) {
    char ***aux_cad = new char **[n_streamers+1]{};
    int **aux_ent = new int *[n_streamers]{};
    long long **aux_long = new long long *[n_streamers]{};

    for (int i=0; i<n_streamers; i++) {
        aux_cad[i] = streamers[i];
        aux_ent[i] = fechas_promedios[i];
        aux_long[i] = tiempo_rep_seguidores[i];
    }
    aux_cad[n_streamers] = nullptr;
    delete [] streamers;
    delete [] fechas_promedios;
    delete [] tiempo_rep_seguidores;
    streamers = aux_cad;
    fechas_promedios = aux_ent;
    tiempo_rep_seguidores = aux_long;
}

void cargar_streamers(const char *file_name, char ***&streamers, int **&fechas_promedios, long long **&tiempo_rep_seguidores) {
    ifstream input;
    abrir_archivo_entrada(file_name, input);
    int n_streamers=0, capacidad=0;
    while (true) {
        char buffer[50]{};
        input.getline(buffer, 50, ',');
        if (input.eof()) break;
        if (n_streamers>=capacidad-1) agregarMemoriaPorIncrementoStreamers(streamers, fechas_promedios, tiempo_rep_seguidores,n_streamers, capacidad);
        leer_guardar_datos(input, streamers, fechas_promedios, tiempo_rep_seguidores, n_streamers, buffer);
        n_streamers++;
    }
    recortar_streamers(n_streamers, streamers, fechas_promedios, tiempo_rep_seguidores);
    input.close();
}

void abrir_archivo_entrada(const char *filename, ifstream &input) {
    input.open(filename, ios::in);
    if (!input.is_open()) {
        cout << "Error al abrir el archivo de entrada" << endl;
        exit(1);
    }
}

void agregarMemoriaPorIncrementoCat(char ***&categorias, int &n_cat, int &capacidad) {
    capacidad+=INCREMENTO;

    if (categorias==nullptr) {
        categorias = new char **[capacidad]{};
    } else {
        char ***aux_cat = new char **[capacidad]{};
        for (int i=0; i<n_cat; i++) aux_cat[i] = categorias[i];
        delete [] categorias;
        categorias = aux_cat;
    }
}

char * asignar_cadena(char *buffer) {
    char *cadena;
    cadena = new char[strlen(buffer)+1]{};
    strcpy(cadena, buffer);
    return cadena;
}

char * leer_cadena(ifstream & input, char del) {
    char buffer[MAX_CAD]{};
    input.getline(buffer, MAX_CAD, del);
    return asignar_cadena(buffer);
}

void recortar_cat(char ***&categorias, int n_cat) {
    char ***aux_cad = new char **[n_cat+1]{};
    for (int i=0; i<n_cat; i++) aux_cad[i] = categorias[i];
    aux_cad[n_cat] = nullptr;
    delete [] categorias;
    categorias = aux_cad;
}

void cargar_categorias(const char *file_name, char ***&categorias) {
    ifstream input;
    abrir_archivo_entrada(file_name, input);
    int n_cat=0, capacidad=0;
    while (true) {
        char buffer[10]{};
        input.getline(buffer, 10, ',');
        if (input.eof()) break;
        if (n_cat >= capacidad-1) agregarMemoriaPorIncrementoCat(categorias, n_cat, capacidad);
        categorias[n_cat] = new char *[3]{};
        char **lista = categorias[n_cat];
        lista[0] = asignar_cadena(buffer);
        lista[1] = leer_cadena(input, ',');
        lista[2] = leer_cadena(input, '\n');
        n_cat++;
    }
    recortar_cat(categorias, n_cat);
    input.close();
}
