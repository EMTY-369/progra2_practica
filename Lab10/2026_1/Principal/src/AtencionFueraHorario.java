public class AtencionFueraHorario extends Atencion {

    public AtencionFueraHorario(){
        super();
    }

    @Override
    public String getTipo(){
        return "AtencionFueraHorario";
    }

    @Override
    public double calcularCosto(){
        if (super.getTipoAtencion().compareTo("VACUNACION")==0) return super.getCodigosVacuna().size()*30*1.5;
        else if (super.getTipoAtencion().compareTo("CONSULTA")==0){
            if(super.getIdPaciente()%2==0) return 40.0*1.5;
            else return 50.0*1.5;
        }
        else if (super.getTipoAtencion().compareTo("OPERACION")==0) return 800.0;
        else if (super.getTipoAtencion().compareTo("INTERNAMIENTO")==0) return 200.0;
        return 0.0;
    }
}
