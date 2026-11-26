import java.util.ArrayList;
import java.util.Scanner;

public abstract class Atencion extends Registro {
    private String dia;
    private int hora;
    private String tipoAtencion;
    private int idPaciente;
    private ArrayList<Integer> codigosVacuna;
    private double costoCalculado;

    public Atencion(){
        hora = 0;
        idPaciente = 0;
        codigosVacuna = new ArrayList<>();
        costoCalculado = 0;
    }

    public abstract String getTipo();
    public abstract double calcularCosto();

    public boolean leer(Scanner input){
        tipoAtencion = input.next();
        idPaciente = input.nextInt();
        if(tipoAtencion.compareTo("VACUNACION")==0){
            while(input.hasNextInt()) {
                int codVac = input.nextInt();
                codigosVacuna.add(codVac);
            }
        }
        return true;
    }

    public void imprimir(){
        System.out.printf("%6s %-25s %-15s %-10s %02d"," ",getTipo(),tipoAtencion,dia,hora);
        if (codigosVacuna.isEmpty()) System.out.printf("%-40s"," -");
        else {
            int i=0;
            String lista_vacunas = " ";
            for(int cod:codigosVacuna){
                if(i==0) lista_vacunas = lista_vacunas + getTipoVacuna(cod);
                else lista_vacunas = lista_vacunas + ", " + getTipoVacuna(cod);
                i++;
            }
            System.out.printf("%-40s", lista_vacunas);
        }
        System.out.printf("S/%10.2f %n", costoCalculado);
    }

    public String getTipoVacuna(int cod) {
        if (cod == 101) return "Parvovirus";
        else if (cod == 102) return "Moquillo";
        else if (cod == 103) return "Rabia";
        else if (cod == 104) return "TripleFelina";

        return null;
    }

    public String getDia() {
        return dia;
    }

    public void setDia(String dia) {
        this.dia = dia;
    }

    public int getHora() {
        return hora;
    }

    public void setHora(int hora) {
        this.hora = hora;
    }

    public String getTipoAtencion() {
        return tipoAtencion;
    }

    public void setTipoAtencion(String tipoAtencion) {
        this.tipoAtencion = tipoAtencion;
    }

    public int getIdPaciente() {
        return idPaciente;
    }

    public void setIdPaciente(int idPaciente) {
        this.idPaciente = idPaciente;
    }

    public ArrayList<Integer> getCodigosVacuna() {
        return codigosVacuna;
    }

    public double getCostoCalculado() {
        return costoCalculado;
    }

    public void setCostoCalculado(double costoCalculado) {
        this.costoCalculado = costoCalculado;
    }
}
