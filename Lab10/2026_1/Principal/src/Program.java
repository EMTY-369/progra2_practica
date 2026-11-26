import java.io.FileNotFoundException;

public class Program {
    public static void main(String[] args) throws FileNotFoundException {
        Veterinaria veterinaria = new Veterinaria("datos.txt");
        veterinaria.cargarDatos();
        veterinaria.procesarDatos();
        veterinaria.imprimirReporte();
    }
}
