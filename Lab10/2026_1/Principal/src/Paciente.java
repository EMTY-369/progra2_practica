import java.util.ArrayList;
import java.util.Scanner;

public class Paciente extends Registro{
    private int id;
    private String nombre;
    private String especie;
    private int dniTutor;
    private String nombreTutor;
    private ArrayList<Atencion> atenciones;
    private double costoTotal;

    public Paciente(){
        id = 0;
        dniTutor = 0;
        costoTotal = 0;
        atenciones = new ArrayList<>();
    }

    public boolean leer(Scanner input){
        if(!input.hasNextInt()) return false;

        id = input.nextInt();
        nombre = input.next();
        especie = input.next();
        dniTutor = input.nextInt();
        nombreTutor = input.next();
        return true;
    }

    public void imprimir(){
        System.out.printf("%-6d %-20s %-15s %-14d %-20s S/%10.2f %n%n",id,nombre,especie,dniTutor,nombreTutor,costoTotal);
        System.out.printf("%6s %-25s %-15s %-10s %-6s %-40s %-15s %n"," ","CLASE_ATENCION","TIPO","DIA","HORA","VACUNAS","COSTO");
        for(Atencion a : atenciones){
            a.imprimir();
        }
    }

    public void actualizarCosto() {
        for(Atencion a: atenciones){
            costoTotal += a.calcularCosto();
            a.setCostoCalculado(a.calcularCosto());
        }
    }

    public int getId() {
        return id;
    }

    public void setId(int id) {
        this.id = id;
    }

    public String getNombre() {
        return nombre;
    }

    public void setNombre(String nombre) {
        this.nombre = nombre;
    }

    public String getEspecie() {
        return especie;
    }

    public void setEspecie(String especie) {
        this.especie = especie;
    }

    public int getDniTutor() {
        return dniTutor;
    }

    public void setDniTutor(int dniTutor) {
        this.dniTutor = dniTutor;
    }

    public String getNombreTutor() {
        return nombreTutor;
    }

    public void setNombreTutor(String nombreTutor) {
        this.nombreTutor = nombreTutor;
    }

    public ArrayList<Atencion> getAtenciones() {
        return atenciones;
    }

    public double getCostoTotal() {
        return costoTotal;
    }

    public void setCostoTotal(double costoTotal) {
        this.costoTotal = costoTotal;
    }
}
