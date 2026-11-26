public class SuscripcionPremium extends Suscripcion {
    public SuscripcionPremium() {
        super();
    }

    @Override
    public void imprimir(){
        System.out.printf("%-15s","PREMIUM");
        super.imprimir();
    }

    @Override
    public String getTipo() {return "PREMIUM";}

    @Override
    public double calcularPrecio() {return 80;}

}
