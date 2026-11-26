import java.io.File;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.Scanner;


public class PlataformaStreaming {
    private final ArrayList<CanalStreaming> canales;
    private final ArrayList<Usuario> usuarios;
    private final ArrayList<Suscripcion> suscripciones;
    private final Scanner input;

    public static final int ANCHO=160;

    public PlataformaStreaming() {
        canales = new ArrayList<>();
        usuarios = new ArrayList<>();
        suscripciones = new ArrayList<>();
        input = new Scanner(System.in);
    }

    public PlataformaStreaming(String file_name) throws FileNotFoundException{
        canales = new ArrayList<>();
        usuarios = new ArrayList<>();
        suscripciones = new ArrayList<>();
        input = new Scanner(new File(file_name));
    }

    public void cargarDatos(){
        cargarCanales();
        cargarUsuarios();
        cargarSuscripciones();
    }

    public void cargarSuscripciones() {
        while(input.hasNext()){
            String tipo = input.next();
            Suscripcion s;
            if(tipo.compareTo("BASICA") == 0) s = new SuscripcionBasica();
            else if (tipo.compareTo("PREMIUM") == 0) s = new SuscripcionPremium();
            else s = new SuscripcionVIP();
            s.leer(input);
            suscripciones.add(s);
            setearDatosListas(s);
        }
        input.close();
    }

    public void setearDatosListas(Suscripcion s) {
        buscarYSetearCanal(s);
        buscarYSetearUsuario(s);
    }

    public void buscarYSetearUsuario(Suscripcion s) {
        for(CanalStreaming c : canales){
            if(c.getId() == s.getIdCanal()) s.setCanal(c);
        }
    }

    public void buscarYSetearCanal(Suscripcion s) {
        for(Usuario u : usuarios){
            if(s.getIdUsuario() == u.getId()){
                s.setUsuario(u);
                u.getSuscripciones().add(s);
            }
        }
    }

    public void cargarUsuarios() {
        while(input.hasNext()){
            Usuario u = new Usuario();
            if(!u.leer(input)) break;
            usuarios.add(u);
        }
        String fin = input.next();
    }

    public void cargarCanales() {
        while(input.hasNext()) {
            CanalStreaming canal = new CanalStreaming();
            if(!canal.leer(input)) break;
            canales.add(canal);
        }
        String fin = input.next();
    }

    public void imprimirReporte(){
        imprimirlinea(ANCHO, '=', true);
        imprimirlinea((ANCHO-19)/2, ' ', false);
        System.out.println("REPORTE DE USUARIOS");
        imprimirlinea(ANCHO, '=', true);
        System.out.printf("%-5s %-25s %-14s %-6s %-15s %-16s %-14s %-30s %-25s %n","ID","Nombre Completo","DNI",
                          "Edad","Ciudad","F. Nac","Teléfono","Email","Ocupación");
        imprimirlinea(ANCHO, '-', true);

        for(Usuario u : usuarios){
            u.imprimir();
        }
        imprimirlinea(ANCHO, '=', true);
    }

    public void imprimirlinea(int ancho, char c, boolean salto) {
        for(int i=0;i<ancho;i++) System.out.print(c);
        if(salto) System.out.println();
    }
}
