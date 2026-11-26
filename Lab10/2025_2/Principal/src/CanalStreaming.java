import java.util.Scanner;

public class CanalStreaming extends Registro {
    private int id;
    private String nombre;
    private String descripcion;
    private String fechaCreacion;
    private long cantVisualizaciones;
    private String categoria;


    public CanalStreaming(){
        id = 0;
        cantVisualizaciones = 0;
    }

    @Override
    public boolean leer(Scanner input){
        if(!input.hasNextInt()) return false;
        id = input.nextInt();
        nombre = input.next();
        descripcion = input.next();
        fechaCreacion = input.next();
        cantVisualizaciones = input.nextLong();
        categoria = input.next();
        return true;
    }

    @Override
    public void imprimir(){

    }

    public int getId() {
        return id;
    }

    public void setId(int id) {
        this.id = id;
    }

    public String getNombre() {
        return nombre;
    }

    public void setNombre(String nombre) {
        this.nombre = nombre;
    }

    public String getDescripcion() {
        return descripcion;
    }

    public void setDescripcion(String descripcion) {
        this.descripcion = descripcion;
    }

    public String getFechaCreacion() {
        return fechaCreacion;
    }

    public void setFechaCreacion(String fechaCreacion) {
        this.fechaCreacion = fechaCreacion;
    }

    public long getCantVisualizaciones() {
        return cantVisualizaciones;
    }

    public void setCantVisualizaciones(long cantVisualizaciones) {
        this.cantVisualizaciones = cantVisualizaciones;
    }

    public String getCategoria() {
        return categoria;
    }

    public void setCategoria(String categoria) {
        this.categoria = categoria;
    }
}
