import java.util.Scanner;

public abstract class Suscripcion extends Registro {
    private int idUsuario;
    private int idCanal;
    private Usuario usuario;
    private CanalStreaming canal;

    public Suscripcion(){
        idCanal=0;
        idUsuario=0;
    }

    public abstract String getTipo();
    public abstract double calcularPrecio();

    @Override
    public boolean leer(Scanner input){
        idUsuario = input.nextInt();
        idCanal = input.nextInt();
        return true;
    }

    @Override
    public void imprimir(){
        System.out.printf("| Usuario: %-6d %-20s | Canal: %-6d %-20s | Precio: %.2f %n",idUsuario,usuario.getNombreCompleto(),
                          idCanal,canal.getNombre(),calcularPrecio());
    }

    public int getIdUsuario() {
        return idUsuario;
    }

    public void setIdUsuario(int idUsuario) {
        this.idUsuario = idUsuario;
    }

    public int getIdCanal() {
        return idCanal;
    }

    public void setIdCanal(int idCanal) {
        this.idCanal = idCanal;
    }

    public Usuario getUsuario() {
        return usuario;
    }

    public void setUsuario(Usuario usuario) {
        this.usuario = usuario;
    }

    public CanalStreaming getCanal() {
        return canal;
    }

    public void setCanal(CanalStreaming canal) {
        this.canal = canal;
    }
}
