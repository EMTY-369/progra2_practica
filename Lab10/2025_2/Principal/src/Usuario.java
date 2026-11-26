import java.util.ArrayList;
import java.util.Scanner;

public class Usuario extends Registro{
    private int id;
    private String nombreCompleto;
    private int dni;
    private int edad;
    private String ciudad;
    private String fechaNacimiento;
    private String telefono;
    private String email;
    private String ocupacion;
    private ArrayList<Suscripcion> suscripciones;

    public Usuario(){
        id = 0;
        dni = 0;
        edad = 0;
        suscripciones = new ArrayList<>();
    }

    @Override
    public boolean leer(Scanner input){
        if(!input.hasNextInt()) return false;

        id = input.nextInt();
        nombreCompleto = input.next();
        dni = input.nextInt();
        edad = input.nextInt();
        ciudad = input.next();
        fechaNacimiento = input.next();
        telefono = input.next();
        email = input.next();
        ocupacion = input.next();
        return true;
    }

    @Override
    public void imprimir(){
        System.out.printf("%-5d %-25s %-14d %-6d %-15s %-16s %-14s %-30s %-25s %n",id,nombreCompleto,dni,edad,ciudad,
                          fechaNacimiento,telefono,email,ocupacion);
        System.out.printf("%21s%n","Suscripciones:");

        double costo_total = 0;
        for(Suscripcion sub : suscripciones){
            System.out.printf("%12s","- ");
            sub.imprimir();
            costo_total+=sub.calcularPrecio();
        }
        System.out.printf("%20s %.2f %n%n","Costo total: ", costo_total);
    }

    public double calcularCosto(){
        double costo = 0.0;
        for(Suscripcion s : suscripciones){
            costo += s.calcularPrecio();
        }
        return costo;
    }

    public int getId() {
        return id;
    }

    public void setId(int id) {
        this.id = id;
    }

    public String getNombreCompleto() {
        return nombreCompleto;
    }

    public void setNombreCompleto(String nombreCompleto) {
        this.nombreCompleto = nombreCompleto;
    }

    public int getDni() {
        return dni;
    }

    public void setDni(int dni) {
        this.dni = dni;
    }

    public int getEdad() {
        return edad;
    }

    public void setEdad(int edad) {
        this.edad = edad;
    }

    public String getCiudad() {
        return ciudad;
    }

    public void setCiudad(String ciudad) {
        this.ciudad = ciudad;
    }

    public String getFechaNacimiento() {
        return fechaNacimiento;
    }

    public void setFechaNacimiento(String fechaNacimiento) {
        this.fechaNacimiento = fechaNacimiento;
    }

    public String getTelefono() {
        return telefono;
    }

    public void setTelefono(String telefono) {
        this.telefono = telefono;
    }

    public String getEmail() {
        return email;
    }

    public void setEmail(String email) {
        this.email = email;
    }

    public String getOcupacion() {
        return ocupacion;
    }

    public void setOcupacion(String ocupacion) {
        this.ocupacion = ocupacion;
    }

    public ArrayList<Suscripcion> getSuscripciones() {
        return suscripciones;
    }
}
