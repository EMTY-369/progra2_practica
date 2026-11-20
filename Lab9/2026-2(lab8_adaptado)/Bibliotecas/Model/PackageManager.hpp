//
// Created by User on 19/11/2026.
//

#ifndef INC_2026_2_LAB8_ADAPTADO__PACKAGEMANAGER_HPP
#define INC_2026_2_LAB8_ADAPTADO__PACKAGEMANAGER_HPP
#include "StandardPackage.hpp"
#include "RefrigeratePackage.hpp"

class PackageManager {
public:
    void load_packages();
    void imprimir_encabezados(ofstream &output_dis, ofstream &output_pdg);
    void process_dispatches();

    PackageManager() = default;
    ~PackageManager();
private:
    class Package *reservar_memoria(char tipo);
    list<class Package*> package_queue;
};


#endif //INC_2026_2_LAB8_ADAPTADO__PACKAGEMANAGER_HPP
