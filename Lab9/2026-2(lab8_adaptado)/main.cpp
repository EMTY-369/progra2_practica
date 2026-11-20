#include "Bibliotecas/Model/PackageManager.hpp"

int main() {
    class PackageManager pucp;

    pucp.load_packages();
    pucp.process_dispatches();

    return 0;
}
