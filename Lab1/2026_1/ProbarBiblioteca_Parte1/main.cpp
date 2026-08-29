
#include "Bibliotecas/SobreCargas.hpp"

int main() {
    struct Mascota mascota1{};
    struct Veterinario veterinario1{};
    struct Atencion atencion1{}, atencion2{};

    ifstream input1, input2, input3;
    abrir_archivo_entrada("ArchivosDeDatos/Mascotas.csv", input1);
    abrir_archivo_entrada("ArchivosDeDatos/Veterinarios.csv" , input2);
    abrir_archivo_entrada("ArchivosDeDatos/Atenciones.csv", input3);

    input1 >> mascota1;
    input2 >> veterinario1;
    input3 >> atencion1;

    atencion1.idAtencion = 1001;
    atencion2.idAtencion = 1002;
    atencion2.fecha = atencion1.fecha;
    atencion2.idMascota = atencion1.idMascota;
    atencion2.idVeterinario = atencion1.idVeterinario;
    atencion2.hora = atencion1.hora;
    //atencion2.hora = 8;
    atencion2.minutos = atencion1.minutos;
    atencion2.estado = asignar_cadena(atencion1.estado);
    atencion2.tipoAtencion = asignar_cadena(atencion1.tipoAtencion);
    cout<<"Atencion1 y Atencion2 son identicos : ";
    if (atencion1 == atencion2) cout<<"Son iguales"<<endl;
    else cout<<"No son iguales"<<endl;

    int fecha=20231105;
    cout<<"La fecha es menor o igual: ";
    if (mascota1 <= fecha) cout<<true<<endl;
    else cout<<false<<endl;

    ofstream output1, output2;
    abrir_archivo_salida("ArchivosDeReporte/impresion_mascota1.txt", output1);
    abrir_archivo_salida("ArchivosDeReporte/impresion_atencion.txt", output2);
    output1 << mascota1;
    output2 << atencion1;
    return 0;
}
