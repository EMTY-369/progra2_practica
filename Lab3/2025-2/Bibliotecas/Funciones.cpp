//
// Created by User on 17/09/2026.
//

#include "Funciones.hpp"

void abrir_archivo_salida(const char *file_name, ofstream &output) {
    output.open(file_name, ios::out);
    if (not output.is_open()) {
        cout << "Error al abrir archivo_salida" << endl;
        exit(1);
    }
}

void imprimir_linea(int n, char c,ofstream &output) {
    for (int i = 0; i < n; i++) output.put(c);
    output.put('\n');
}

void imprimir_comentarios(void * dato, ofstream & output) {
    void **arr_comentarios = (void **)dato;
    imprimir_linea(ANCHO, '-', output);
    for (int i = 0; arr_comentarios[i]; i++) {
        void **datos_comentarios = (void **)arr_comentarios[i];
        output<<setw(20)<<(char *)datos_comentarios[0]<<(char *)datos_comentarios[1]<<endl;
    }
}

void imprimir_streamers(void * streamers) {
    ofstream output;
    abrir_archivo_salida("ArchivosDeReporte/Reporte.txt", output);
    void **arr_streamers = (void **)streamers;
    for (int i = 0; arr_streamers[i]; i++) {
        void **datos = (void **)arr_streamers[i];
        imprimir_linea(ANCHO, '=', output);
        output<<left<<setw(20)<<"Cuenta"<<setw(20)<<"Seguidores"<<endl;
        output<<setw(20)<<(char *)datos[CUENTA]<<setw(20)<<*(int *)datos[SEGUIDORES]<<endl;
        imprimir_linea(ANCHO, '-', output);
        output<<"Comentarios emitidos:"<<endl;
        imprimir_linea(ANCHO, '-', output);
        output<<setw(20)<<"Receptor"<<"Texto"<<endl;
        if (datos[COMENTARIOS] != nullptr) imprimir_comentarios(datos[COMENTARIOS], output);
        //imprimir_linea(ANCHO, '=', output);
    }
}

void agregar_espacios(void *&comentarios, int &n_comentarios, int &capacidad) {
    void **datos_comentarios = (void **)comentarios;
    capacidad += INCREMENTO;
    if (datos_comentarios == nullptr) {
        datos_comentarios = new void *[capacidad] {};
        n_comentarios=1;
    } else {
        void **aux_datos_comentarios = new void *[capacidad]{};
        for (int i = 0; i < n_comentarios; i++) aux_datos_comentarios[i] = datos_comentarios[i];
        delete [] datos_comentarios;
        datos_comentarios = aux_datos_comentarios;
    }
    comentarios = datos_comentarios;
}

void actualizar_comentarios(void * streamers, void * comentarios) {
    void **arr_comentarios = (void **)comentarios, **arr_streamers = (void **)streamers;

    for (int i = 0; arr_streamers[i]; i++) {
        void **datos_streamer = (void **)arr_streamers[i];
        char *cuenta = (char *)datos_streamer[CUENTA];
        int n_comentarios = 0, capacidad = 0;
        for (int j = 0; arr_comentarios[j]; j++) {
            void **datos_comentarios = (void **)arr_comentarios[j];
            char *emisor = (char*)datos_comentarios[EMISOR];
            if (strcmp(emisor, cuenta) == 0) {
                if (n_comentarios==capacidad) agregar_espacios(datos_streamer[COMENTARIOS], n_comentarios, capacidad);
                void **comentario = new void *[2]{}, **arr_coments = (void **)datos_streamer[COMENTARIOS];

                comentario[0] = asignar_cadena((char *)datos_comentarios[RECEPTOR]);
                comentario[1] = asignar_cadena((char *)datos_comentarios[TEXTO]);
                arr_coments[n_comentarios-1] = comentario;
                n_comentarios++;
            }
        }
    }
}

void * leer_datos_comentario( ifstream &input) {
    char cod[MAX_CAD]{}, *texto, *emisor, *receptor,c;
    input.getline(cod, MAX_CAD, ',');
    if (input.eof()) return nullptr;

    texto = leer_cadena(input, '[');
    emisor = leer_cadena(input, ' ');
    receptor = leer_cadena(input, ']');
    input.get(c);

    void **comentario = new void *[4]{};
    comentario[COD] = asignar_cadena(cod);
    comentario[EMISOR] = emisor;
    comentario[RECEPTOR] = receptor;
    comentario[TEXTO] = texto;
    return comentario;
}

void aumentar_espacios(void **&arr_coment, int &n_comentarios, int &capacidad) {
    capacidad += INCREMENTO;
    if (arr_coment == nullptr) {
        arr_coment = new void *[capacidad] {};
        n_comentarios=1;
    } else {
        void **aux_comentarios = new void *[capacidad]{};
        for (int i = 0; i < n_comentarios; i++) aux_comentarios[i] = arr_coment[i];
        delete [] arr_coment;
        arr_coment = aux_comentarios;
    }
}

void cargar_comentarios(void *&comentarios) {
    ifstream input;
    abrir_archivo_entrada("ArchivosDeDatos/comentarios.csv", input);
    void **arr_coment = (void **)comentarios, *comentario;
    arr_coment = nullptr;
    int n_comentarios=0, capacidad=0;
    while (true) {
        comentario = leer_datos_comentario(input);
        if (input.eof()) break;
        if (n_comentarios == capacidad) aumentar_espacios(arr_coment, n_comentarios, capacidad);
        arr_coment[n_comentarios-1] = comentario;
        n_comentarios++;
    }

    comentarios = arr_coment;
}

void abrir_archivo_entrada(const char *file_name, ifstream &input) {
    input.open(file_name, ios::in);
    if (not input.is_open()) {
        cout << "Error al abrir el archivo de entrada" << endl;
        exit(1);
    }
}

char * asignar_cadena(char * buffer) {
    char *cadena;
    cadena = new char[strlen(buffer)+1];
    strcpy(cadena, buffer);
    return cadena;
}

char * leer_cadena( ifstream & input, char del) {
    char buffer[MAX_CAD]{};
    input.getline(buffer, MAX_CAD, del);
    return asignar_cadena(buffer);
}

void * leer_datos_streamer( ifstream & input) {
    char buffer[MAX_CAD]{},c, *categoria;
    long long tiempo;
    int prom, *ptr_seguidores=new int;

    input.getline(buffer, MAX_CAD, ',');
    if (input.eof()) return nullptr;
    input>>tiempo>>c>>prom>>c>>*ptr_seguidores>>c;
    categoria = leer_cadena(input,'\n');

    void **datos_streamer = new void *[4]{};
    datos_streamer[CUENTA] = asignar_cadena(buffer);
    datos_streamer[SEGUIDORES] = ptr_seguidores;
    datos_streamer[CATEGORIA] = categoria;
    datos_streamer[COMENTARIOS] = nullptr;
    return datos_streamer;
}

void incrementar_espacios(void **&arr_streamers, int &n_streamers, int &capacidad) {
    capacidad += INCREMENTO;
    if (arr_streamers == nullptr) {
        arr_streamers = new void *[capacidad] {};
        n_streamers=1;
    } else {
        void **aux_streamers = new void *[capacidad]{};
        for (int i = 0; i < n_streamers; i++) aux_streamers[i] = arr_streamers[i];
        delete [] arr_streamers;
        arr_streamers = aux_streamers;
    }
}

void cargar_streamers(void *&streamers) {
    ifstream input;
    abrir_archivo_entrada("ArchivosDeDatos/streamers.csv", input);
    void **arr_streamers=(void **)streamers, *streamer;
    arr_streamers = nullptr;
    int n_streamers=0, capacidad = 0;
    while (true) {
        streamer=leer_datos_streamer(input);
        if (input.eof()) break;
        if (n_streamers == capacidad) incrementar_espacios(arr_streamers, n_streamers, capacidad);
        arr_streamers[n_streamers-1]=streamer;
        n_streamers++;
    }

    streamers = arr_streamers;
}
