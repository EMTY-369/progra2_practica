public class AtencionFinSemana extends Atencion {

    public AtencionFinSemana(){
        super();
    }

    @Override
    public String getTipo(){
        return "AtencionFinSemana";
    }

    @Override
    public double calcularCosto(){
        if (super.getTipoAtencion().compareTo("VACUNACION")==0) return super.getCodigosVacuna().size()*30*2;
        else if (super.getTipoAtencion().compareTo("CONSULTA")==0){
            if(super.getIdPaciente()%2==0) return 40.0*2;
            else return 50.0*2;
        }
        else if (super.getTipoAtencion().compareTo("OPERACION")==0) return 800.0;
        else if (super.getTipoAtencion().compareTo("INTERNAMIENTO")==0) return 300.0;
        return 0.0;
    }
}
