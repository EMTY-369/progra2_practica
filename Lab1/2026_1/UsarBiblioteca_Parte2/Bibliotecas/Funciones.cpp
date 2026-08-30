//
// Created by alois on 28/8/26.
//

#include "Funciones.hpp"

void buscar_imprimir_atenciones(const struct SistemaHuellitas sistema, int id_mascota, ofstream & output) {
    bool tuvoAtenciones = false;
    for (int i = 0; i < sistema.numAtenciones; i++) {
        if (id_mascota == sistema.atenciones[i].idMascota) {
            output << sistema.atenciones[i];
            tuvoAtenciones = true;
        }
    }
    if (not tuvoAtenciones) output<<"No tiene atenciones registradas"<<endl;
    imprimir_linea(ANCHO_REPORTE,'-', output);
}

void imprimirMascotasConAtenciones(const struct SistemaHuellitas &sistema, const char * file_name) {
    ofstream output;
    abrir_archivo_salida(file_name, output);

    imprimir_titulo(" LISTADO DE MASCOTAS Y SUS ATENCIONES ",output);

    for (int i = 0; i < sistema.numMascotas; i++) {
        output << sistema.mascotas[i];
        output << endl;
        buscar_imprimir_atenciones(sistema, sistema.mascotas[i].idMascota, output);
    }
    output<<"TOTAL:  "<<sistema.numMascotas<<" mascotas, "<<sistema.numAtenciones<<" atenciones"<<endl;
    output.close();
}


void imprimir_linea(int n, char c, ofstream & output, bool slash) {
    for (int i = 0; i < n; i++) output.put(c);
    if (slash) output.put('\n');
}

void centrear(const char *texto, int espacio, ofstream & output, bool slash, char c) {
    int m=strlen(texto), n = (espacio - m)/2;
    imprimir_linea(n, c, output, false);
    output<<texto;
    imprimir_linea(espacio - (n+m), c, output, slash);
}

void imprimir_titulo(const char*title, ofstream & output) {
    imprimir_linea(ANCHO_REPORTE, '=', output);
    centrear(title, ANCHO_REPORTE, output, true, '*');
    imprimir_linea(ANCHO_REPORTE, '=', output);
}

void listaMascotasAEsterilizar(const struct Mascota *mascota, int num_mascotas, int fecha_actural, const char *file_name) {
    ofstream output;
    abrir_archivo_salida(file_name, output);

    imprimir_titulo(" MASCOTAS QUE DEBEN SER ESTERILIZADAS ", output);

    for (int i = 0; i < num_mascotas; i++) {
        if ((mascota[i].fechaNacimiento + SEIS_MESES) >= fecha_actural) {
            output << mascota[i];
            output << endl;
        }
    }
    output.close();
}

void copiar_struct(struct Atencion & destino, const struct Atencion & origen) {
    destino.idVeterinario = origen.idVeterinario;
    destino.idMascota = origen.idMascota;
    destino.fecha = origen.fecha;
    destino.hora = origen.hora;
    destino.minutos = origen.minutos;
    destino.estado = asignar_cadena(origen.estado);
    destino.tipoAtencion = asignar_cadena(origen.tipoAtencion);
}

void validar_guardar(ifstream &input, const struct Atencion & atencion, struct Atencion *&arr_atenciones, int &n_atenciones, int &
                     s_programar, int id_inicia) {
    if (strcmp(atencion.estado, "PROGRAMADA")==0) {
        cout<<"Horario ocupado del veterinario ID: "<<atencion.idVeterinario<<" el "<<atencion.fecha
            <<" a las "<<setfill('0')<<setw(2)<<atencion.hora<<":"<<setw(2)<<atencion.minutos
            <<"."<<setfill(' ')<<endl;
    } else s_programar++;
    copiar_struct(arr_atenciones[n_atenciones], atencion);
    arr_atenciones[n_atenciones].idAtencion = id_inicia+n_atenciones;
    n_atenciones++;
}

void registrarAtenciones(const char * file_name, struct Atencion *&arr_atenciones, int &n_atenciones) {
    ifstream input;
    abrir_archivo_entrada(file_name, input);

    arr_atenciones = new struct Atencion[MAX_ATENCIONES]{};

    int id_inicia=1001, s_programar=0;
    while (true) {
        struct Atencion atencion{};
        input >> atencion;
        if (input.eof()) break;
        validar_guardar(input, atencion, arr_atenciones, n_atenciones, s_programar, id_inicia);
    }
    cout<<s_programar<<" ATENCION(ES) SIN PROGRAMAR"<<endl;
}

void cargar_veterinarios(ifstream & input, struct Veterinario *&veterinarios, int &n_veterinarios) {
    while (true) {
        input >> veterinarios[n_veterinarios];
        if (input.eof()) break;
        n_veterinarios++;
    }
}

void cargar_mascotas(ifstream &input, struct Mascota *&mascotas, int &n_mascotas) {
    while (true) {
        input >> mascotas[n_mascotas];
        if (input.eof()) break;
        n_mascotas++;
    }
}


void cargarDatos(const char * file_mascota, const char * file_veterinario, struct Mascota *&arr_mascotas, struct Veterinario *&arr_veterinarios,
                 int &n_mascotas, int &n_veterinarios) {
    ifstream inputM, inputV;
    abrir_archivo_entrada(file_mascota, inputM);
    abrir_archivo_entrada(file_veterinario, inputV);

    arr_mascotas = new struct Mascota[MAX_MASCOTAS]{};
    arr_veterinarios = new struct Veterinario[MAX_VETERINARIOS]{};

    cargar_mascotas(inputM, arr_mascotas, n_mascotas);
    cargar_veterinarios(inputV, arr_veterinarios, n_veterinarios);
}
