#include "Bibliotecas/Models/SistemaDeAtencion.hpp"

int main() {
    class SistemaDeAtencion erasmo;
    erasmo.cargarPacientes("ArchivosDeDatos/Pacientes.csv");
    erasmo.cargarMedicos("ArchivosDeDatos/Especialidades_Medicos.csv");
    erasmo.cargarTriajes("ArchivosDeDatos/RegistrosDeTriajes.csv");
    erasmo.cargarAtenciones("ArchivosDeDatos/Atenciones.csv");
    erasmo.llenarAtenciones();
    erasmo.llenarAtencionesDePacientes();
    erasmo.llenarAtencionesDeMedicos();
    erasmo.reporteDeAtencionesPorPaciente("ArchivosDeReporte/pacientes.txt");
    erasmo.reporteDeAtencionesPorMedico("ArchivosDeReporte/medicos.txt");

    return 0;
}
