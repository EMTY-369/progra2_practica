
#include "Bibliotecas/SobreCargas.hpp"

int main() {
    struct Mascota mascota{};
    struct Veterinario veterinario{};
    "ArchivosDeDatos/Mascotas.csv" >> mascota;
    "ArchivosDeDatos/Veterinarios.csv" >> veterinario;
    return 0;
}
