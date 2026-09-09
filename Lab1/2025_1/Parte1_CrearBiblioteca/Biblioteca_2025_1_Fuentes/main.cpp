#include "Bibliotecas/Sobrecargas.hpp"

int main() {
    char t1[]="HoLa", t2[]="hola", t3[]="Erick", t4[]="eliminar", t5[]="Holas UwU";
    struct CadenaDeCaracteres c1, c2, c3 , c4;
    !c4;
    c1 <= t1; c2 <= t2; c3 <= t3; c4 <= t4;

    cout << c4.cadena << "   " << c4.capacidad << "   " << c4.longitud << endl;
    //!c4;
    //cout << c4.cadena << "   " << c4.capacidad << "   " << c4.longitud << endl;
    cout << (c4 += t3) <<endl;

    c4 <= 10;
    cout << (c4 += c3) << "    " <<c4.cadena<<endl;

    c4<=c3;
    cout << c4.cadena <<endl;

    c4<=t5;
    cout << (c4 == c1) <<endl;
    cout << (c3 < c2) <<endl;
    cout << (c2 > c3.cadena) <<endl;

    ifstream input;
    abrir_archivo_entrada("ArchivosDeDatos/Infracciones de transito.txt", input);

    struct CadenaDeCaracteres leer{};
    cout<<(input>>leer)<<"      "<<leer.cadena<<endl;
    !leer;
    input>>ws;
    cout << (input>>leer) << "     " << leer.cadena <<endl;

    c1 && c2;
    cout << c1.cadena << "    "<<c2.cadena<<endl;

    ofstream output;
    abrir_archivo_salida("ArchivosDeReporte/prueba.txt", output);

    output << c3;

    return 0;
}
