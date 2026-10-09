//
// Created by User on 8/10/2026.
//

#include "GestorStreamers.hpp"

class Streamer * GestorStreamers::get_data() const {
    return data;
}

void GestorStreamers::set_data(class Streamer * const data) {
    this->data = data;
}

class Streamer * GestorStreamers::get_data_vista() const {
    return dataVista;
}

void GestorStreamers::set_data_vista(class Streamer * const data_vista) {
    dataVista = data_vista;
}

int GestorStreamers::get_cantidad_datos() const {
    return cantidad_datos;
}

void GestorStreamers::set_cantidad_datos(const int cantidad_datos) {
    this->cantidad_datos = cantidad_datos;
}

int GestorStreamers::get_cantidad_datos_vista() const {
    return cantidad_datos_vista;
}

void GestorStreamers::set_cantidad_datos_vista(const int cantidad_datos_vista) {
    this->cantidad_datos_vista = cantidad_datos_vista;
}

GestorStreamers::GestorStreamers() {
    data = new Streamer[MAX_S]{};
    dataVista = nullptr;
    cantidad_datos = 0;
    cantidad_datos_vista = 0;
}

GestorStreamers::~GestorStreamers() {
    delete[] data;
    delete[] dataVista;
}

void GestorStreamers::cargar_datos(const char *file_name) {
    ifstream input;
    Utils::abrir_archivo(input, file_name);

    while (true) {
        class Streamer s;
        s.leer_streamer(input);
        if (input.eof()) break;
        data[cantidad_datos].copiar(s);
        cantidad_datos++;
    }
    cout << "Datos cargados" << endl;
    input.close();
}

void GestorStreamers::mostrar_menu() {
    while (true) {
        char opcion = escoger_opciones_menu();
        if (opcion == 'a') cargar_datos("../ArchivosDeDatos/streamers.csv");
        if (opcion == 'b' or opcion == 'c') crear_reporte(opcion);
        if (opcion == 'e') break;
    }
}

char GestorStreamers::escoger_opciones_menu() {
    char option;
    cout << "Escoge una opcion del menu:"<<endl;
    cout << "a) Cargar Datos"<<endl;
    cout << "b) Mostrar Reporte"<<endl;
    cout << "c) Generar Reporte"<<endl;
    cout << "d) Generar Todos los reportes"<<endl;
    cout << "e) Terminar"<<endl;
    cin >> option;
    return option;
}

void GestorStreamers::crear_reporte(char opcion) {
    char opcion2 = escoger_op_reporte(), *file_name=nullptr;
    copiar_datos();

    if (opcion2 == '1') {
        qsort(dataVista, cantidad_datos_vista, sizeof(Streamer), comparar_seguidores);
        cortar_datos(10);
        file_name = Utils::asignar_cadena("../ArchivosDeReporte/Top10NumSeg.txt");
    }
    if (opcion2 == '2') {
        qsort(dataVista, cantidad_datos_vista, sizeof(Streamer), comparar_tiempo_total);
        cortar_datos(10);
        file_name = Utils::asignar_cadena("../ArchivosDeReporte/Bottom10TempTotalTrans.txt");
    }
    if (opcion2 == '3') {
        qsort(dataVista, cantidad_datos_vista, sizeof(Streamer), compara_catg_prom_espec);
        cortar_datos(5);
        file_name = Utils::asignar_cadena("../ArchivosDeReporte/Top5CatgMayorPromEspec.txt");
    }
    if (opcion2 == '4') {
        qsort(dataVista, cantidad_datos_vista, sizeof(Streamer), comparar_categorias);
        cortar_datos(cantidad_datos);
        file_name = Utils::asignar_cadena("../ArchivosDeReporte/OrdenadoPorCategorias.txt");
    }
    if (opcion2 == '5');

    ofstream output;
    Utils::abrir_archivo(output, file_name);

    for (int i = 0; i < cantidad_datos_vista; i++) {
        if (opcion == 'b') dataVista[i].mostrar_streamer_consola();
        if (opcion == 'c') dataVista[i].mostrar_streamer_arch(output);
    }
    output.close();
    delete[] file_name;
}

char GestorStreamers::escoger_op_reporte() {
    char option;
    cout << "Escoge una opcion para mostrar reporte:"<<endl;
    cout << "1) Reporte Top10 streamers por número de seguidores."<<endl;
    cout << "2) Reporte Bottom10 streamers por tiempo total transmitido."<<endl;
    cout << "3) Reporte Top5 categorías con mayor promedio de espectadores."<<endl;
    cout << "4) Reporte de Categoría"<<endl;
    cout << "5) Reporte de Influencia"<<endl;
    cin >> option;
    return option;
}

void GestorStreamers::copiar_datos() {
    if (dataVista != nullptr) {
        delete[] dataVista;
        cantidad_datos_vista = 0;
    }
    dataVista = new Streamer[cantidad_datos]{};

    for (int i = 0; i < cantidad_datos; i++) {
        dataVista[i].copiar(data[i]);
        cantidad_datos_vista++;
    }
}

void GestorStreamers::cortar_datos(int capacidad) {
    class Streamer *aux = new Streamer[capacidad]{};
    for (int i = 0; i < capacidad; i++) {
        aux[i].copiar(dataVista[i]);
    }
    delete[] dataVista;
    dataVista = aux;
    cantidad_datos_vista = capacidad;
}

int comparar_seguidores(const void *a, const void *b) {
    Streamer *s1 = (Streamer *)a;
    Streamer *s2 = (Streamer *)b;
    return s2->get_n_seguidores() - s1->get_n_seguidores();
}

int comparar_tiempo_total(const void *a, const void *b) {
    Streamer *s1 = (Streamer *)a;
    Streamer *s2 = (Streamer *)b;
    if (s1->get_tiempo_total() > s2->get_tiempo_total()) return 1;
    if (s1->get_tiempo_total() == s2->get_tiempo_total()) return 0;
    if (s1->get_tiempo_total() < s2->get_tiempo_total()) return -1;
}

int compara_catg_prom_espec(const void *a, const void *b) {
    Streamer *s1 = (Streamer *)a;
    Streamer *s2 = (Streamer *)b;
    int num;
    double num2;
    num2 = (s2->get_promedio_spectadores() - s1->get_promedio_spectadores());
    if (fabs(num2)<0.001) {
        char cadena1[MAX_CAD]{}, cadena2[MAX_CAD]{};
        s1->get_categoria(cadena1);
        s2->get_categoria(cadena2);
        num = strcmp(cadena1, cadena2);
    } else {
        if (num2 < 0) num = -1;
        if (num2 > 0) num = 1;
    }
    return num;
}

int comparar_categorias(const void *a, const void *b) {
    Streamer *s1 = (Streamer *)a;
    Streamer *s2 = (Streamer *)b;
    char cadena1[MAX_CAD]{}, cadena2[MAX_CAD]{};
    s1->get_categoria(cadena1);
    s2->get_categoria(cadena2);
    return strcmp(cadena1, cadena2);
}
