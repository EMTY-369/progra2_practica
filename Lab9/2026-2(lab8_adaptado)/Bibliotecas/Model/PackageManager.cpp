//
// Created by User on 19/11/2026.
//

#include "PackageManager.hpp"

void PackageManager::load_packages() {
    ifstream input_pro, input_pack;
    Utils::abrir_archivo(input_pro, "ArchivosDeDatos/products.csv");
    Utils::abrir_archivo(input_pack, "ArchivosDeDatos/packages.csv");

    while (true) {
        char tipo;
        input_pack >> tipo;
        if (input_pack.eof()) break;
        input_pack.get();
        class Package *p = reservar_memoria(tipo);
        if (p == nullptr) {input_pack.ignore(100,'\n'); continue;}
        p->leer(input_pack);
        p->leer_productos(input_pro);
        package_queue.push_back(p);
    }
    input_pack.close();
    input_pro.close();
}

void PackageManager::imprimir_encabezados(ofstream &output_dis, ofstream &output_pdg) {
    output_dis<<"============================ DISPATCHED PACKAGES ============================"<<endl<<endl;
    output_pdg<<"============================ PENDING PACKAGES ============================"<<endl<<endl;
}

void PackageManager::process_dispatches() {
    ofstream output_dis, output_pdg;
    Utils::abrir_archivo(output_dis, "ArchivosDeReporte/dispatch.txt");
    Utils::abrir_archivo(output_pdg, "ArchivosDeReporte/pending.txt");
    output_dis<<fixed; output_pdg<<fixed;
    output_dis.precision(2); output_pdg.precision(2);

    imprimir_encabezados(output_dis, output_pdg);
    int dis=0, pdg=0;
    while (not package_queue.empty()) {
        class Package *p = package_queue.front();
        if (p->can_dispatch()) {
            p->imprimir(output_dis);
            output_dis<<"------------------------------------------------------------------------"<<endl;
            dis ++;
        } else {
            p->imprimir(output_pdg);
            output_pdg<<"------------------------------------------------------------------------"<<endl;
            pdg ++;
        }
        delete p;
        package_queue.pop_front();
    }
    output_dis.close(); output_pdg.close();
}

PackageManager::~PackageManager() {
    auto it = package_queue.begin();
    while (it != package_queue.end()) {
        delete *it;
        ++it;
    }
    package_queue.clear();
}

class Package * PackageManager::reservar_memoria(char tipo) {
    if (tipo == 'S') return new StandardPackage();
    else if (tipo == 'R') return new RefrigeratePackage();
    else return nullptr;
}
