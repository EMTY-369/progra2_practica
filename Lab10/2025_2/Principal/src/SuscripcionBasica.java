public class SuscripcionBasica extends Suscripcion {
    public SuscripcionBasica(){
        super();
    }

    @Override
    public void imprimir(){
        System.out.printf("%-15s","BASICA");
        super.imprimir();
    }

    @Override
    public String getTipo() {return "BASICA";}

    @Override
    public double calcularPrecio() {return 50;}
}
