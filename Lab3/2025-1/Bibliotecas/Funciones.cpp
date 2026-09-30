#include "Funciones.hpp"

void recorrer_tabla(const struct Tabla &t) {
    void *cursor = abrir_cursor(t);
    while (hay_siguiente(cursor)) {
        int id = *(int *)obtener_campo(cursor, 1);
        char *nombre = (char *)obtener_campo(cursor, 3);
        double nota = *(double *)obtener_campo(cursor, 4);
        cout <<id<<";"<<nombre<<";"<<nota<<endl;
    }
}

void *obtener_campo(void *& cursor, int num_campo) {
    if (cursor == nullptr) return nullptr;
    void **casilla = static_cast<void **>(cursor);
    void **fila = static_cast<void **>(*casilla);
    if (fila == nullptr or num_campo<1) return nullptr;
    return fila[num_campo-1];
}

bool hay_siguiente(void *&cursor) {
    static bool primera_vez = true;

    if (cursor == nullptr) {
        primera_vez = true;
        return false;
    }

    void **casilla = static_cast<void **>(cursor);
    if (primera_vez) primera_vez = false;
    else casilla++;
    cursor = casilla;

    if (*casilla == nullptr) {
        primera_vez = true;
        return false;
    }
    return true;
}

void *abrir_cursor(const struct Tabla &t) {
    if (t.cant_fil >= 1) {
        return t.filas;
    }
    return nullptr;
}

void abrir_archivo_lectura(ifstream &input, const char *file_name) {
    input.open(file_name, ios::in);
    if (not input.is_open()) {
        cout << "Error al abrir el archivo lectura" << endl;
        exit(1);
    }
}

char * asignar_cadena(char *buffer) {
    char *cadena;
    cadena = new char[strlen(buffer) + 1];
    strcpy(cadena, buffer);
    return cadena;
}

char * leer_cadena(ifstream & input, char del) {
    char buffer[MAX_CAD]{};
    input.getline(buffer, MAX_CAD, del);
    return asignar_cadena(buffer);
}

void * leer_registro(ifstream & input) {
    int cod, *ptr_cod;
    char *descripcion, *tipo;
    input >> cod;
    if (input.eof()) return nullptr;
    input.get();
    ptr_cod = new int;
    *ptr_cod = cod;
    descripcion = leer_cadena(input, ';');
    tipo = leer_cadena(input, ';');
    double *multa = new double;
    input >> *multa;

    void **registro = new void *[4]{};
    registro[COD] = ptr_cod;
    registro[DESCRIP] = descripcion;
    registro[TIPO] = tipo;
    registro[MULTA] = multa;
    return registro;
}

void leer_infracciones(struct Tabla & t, const char * file_name) {
    ifstream input;
    abrir_archivo_lectura(input, file_name);

    while (true) {
        void *registro = leer_registro(input);
        if (input.eof()) break;
        void *fila = insertar_fila(t);
        void **datos = static_cast<void **>(registro);
        insertar_campo(t,fila,1, datos[COD]);
        insertar_campo(t,fila,2, datos[DESCRIP]);
        insertar_campo(t,fila,3, datos[TIPO]);
        insertar_campo(t,fila,4, datos[MULTA]);
    }
}

void cargar_tabla_infracciones(struct Tabla &t, const char *file_name) {
    inicializar_tabla(t);
    insertar_columna(t, (void *)"CODIGO INFRACCION");
    insertar_columna(t, (void *)"DESCRIPCION");
    insertar_columna(t, (void *)"TIPO");
    insertar_columna(t, (void *)"VALOR MULTA");

    leer_infracciones(t, file_name);
}

void insertar_campo(struct Tabla &t, void * fila, int num_campo, void * dato) {
    if (num_campo > t.cant_col or num_campo<=0) return;
    void **arr_filas = static_cast<void **>(fila);
    arr_filas[num_campo - 1] = dato;
}

void *insertar_fila(struct Tabla &t) {
    void **fila, **lista_filas = static_cast<void **>(t.filas);
    t.cant_fil++;
    if (t.cant_fil >= t.cap_fil) incrementar_espacios(lista_filas, t.cant_fil, t.cap_fil, INC_FIL);
    fila = new void *[t.cant_col]{};
    lista_filas[t.cant_fil - 1] = fila;
    t.filas = lista_filas;
    return lista_filas[t.cant_fil - 1];
}

void incrementar_espacios(void ** &lista, int &cant, int &cap, int inc) {
    cap += inc;
    if (lista == nullptr) {
        lista = new void *[cap]{};
    } else {
        void **aux_col = new void *[cap]{};
        for (int i = 0; i < cant; i++) aux_col[i] = lista[i];
        delete [] lista;
        lista = aux_col;
    }
}

void insertar_columna(struct Tabla &t, void *col) {
    void **lista_col = static_cast<void **>(t.columnas);
    if (t.cant_col+1>=t.cap_col) incrementar_espacios(lista_col, t.cant_col, t.cap_col, INC_COL);
    lista_col[t.cant_col] = col;
    t.cant_col++;
    t.columnas = lista_col;
}

void inicializar_tabla(struct Tabla &t) {
    t.filas = nullptr;
    t.columnas = nullptr;
    t.cant_col = 0;
    t.cant_fil = 0;
    t.cap_col = 0;
    t.cap_fil = 0;
}