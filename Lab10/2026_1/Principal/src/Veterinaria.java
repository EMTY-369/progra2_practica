import java.io.File;
import java.io.FileNotFoundException;
import java.nio.file.FileAlreadyExistsException;
import java.util.ArrayList;
import java.util.Scanner;

public class Veterinaria {
    private ArrayList<Paciente> pacientes;
    private ArrayList<Atencion> atenciones;
    private Scanner input;

    public static final int ANCHO = 120;

    public Veterinaria(){
        pacientes = new ArrayList<>();
        atenciones = new ArrayList<>();
        input = new Scanner(System.in);
    }

    public Veterinaria(String file_name) throws FileNotFoundException {
        pacientes = new ArrayList<>();
        atenciones = new ArrayList<>();
        input = new Scanner(new File(file_name));
    }

    public void cargarDatos(){
        cargarPacientes();
        cargarAtenciones();
        input.close();
    }

    public void cargarAtenciones() {
        while(input.hasNext()){
            String dia = input.next();
            int hora = input.nextInt();
            Atencion a = asignarMemoria(dia, hora);
            a.leer(input);
            a.setDia(dia);
            a.setHora(hora);
            atenciones.add(a);
        }
    }

    private Atencion asignarMemoria(String dia, int hora) {
        if (dia.compareTo("Sabado")!=0 && dia.compareTo("Domingo")!=0 && hora>=6 && hora<=19) return new AtencionRegular();
        else if (dia.compareTo("Sabado")!=0 && dia.compareTo("Domingo")!=0 && (hora>=20 && hora<=24) || (hora>=0 && hora<=5)) return new AtencionFueraHorario();
        else if (dia.compareTo("Sabado")==0 || dia.compareTo("Domingo")==0) return new AtencionFinSemana();
        return null;
    }

    public void cargarPacientes() {
        while (input.hasNext()){
            Paciente p = new Paciente();
            if(!p.leer(input)){ input.next(); break;}
            pacientes.add(p);
        }
    }

    public void procesarDatos(){
        for(Atencion a: atenciones){
            Paciente p = buscarPaciente(a.getIdPaciente());
            if (p!=null) p.getAtenciones().add(a);
        }

        for(Paciente p: pacientes){
            p.actualizarCosto();
        }
    }

    private Paciente buscarPaciente(int idPaciente) {
        for(Paciente p: pacientes){
            if (idPaciente==p.getId()) return p;
        }
        return null;
    }

    public void imprimirReporte(){
        imprimir_linea(ANCHO, '=', true);
        imprimir_linea((ANCHO-33)/2, ' ', false);
        System.out.println("REPORTE DE ATENCIONES VETERINARIA");
        imprimir_linea(ANCHO, '=', true);

        System.out.printf("%-6s %-20s %-15s %-14s %-20s %-16s %n","ID","NOMBRE","ESPECIE","DNI_TUTOR","NOMBRE_TUTOR","TOTAL");
        for(Paciente p : pacientes){
            imprimir_linea(ANCHO, '-', true);
            p.imprimir();
        }
        imprimir_linea(ANCHO, '=', true);
    }

    private void imprimir_linea(int ancho, char c, boolean slash_n) {
        for(int i=0; i<ancho; i++) System.out.print(c);
        if(slash_n) System.out.println();
    }
}
