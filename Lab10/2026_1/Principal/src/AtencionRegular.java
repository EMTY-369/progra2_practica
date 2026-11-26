public class AtencionRegular extends Atencion {

    public AtencionRegular(){
        super();
    }

    @Override
    public String getTipo(){
        return "AtencionRegular";
    }

    @Override
    public double calcularCosto(){
        if (super.getTipoAtencion().compareTo("VACUNACION")==0) return super.getCodigosVacuna().size()*30;
        else if (super.getTipoAtencion().compareTo("CONSULTA")==0){
            if(super.getIdPaciente()%2==0) return 40.0;
            else return 50.0;
        }
        else if (super.getTipoAtencion().compareTo("OPERACION")==0) return 500.0;
        else if (super.getTipoAtencion().compareTo("INTERNAMIENTO")==0) return 200.0;
        return 0.0;
    }
}
