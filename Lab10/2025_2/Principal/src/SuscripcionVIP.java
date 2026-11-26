public class SuscripcionVIP extends Suscripcion {
    public SuscripcionVIP(){
        super();
    }

    @Override
    public void imprimir(){
        System.out.printf("%-15s","VIP");
        super.imprimir();
    }

    @Override
    public String getTipo() {return "VIP";}

    @Override
    public double calcularPrecio() {return 100;}

}
