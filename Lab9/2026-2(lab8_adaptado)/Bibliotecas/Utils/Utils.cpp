//
// Created by User on 19/11/2026.
//

#include "Utils.hpp"

void Utils::abrir_archivo(ifstream &input, const string &file_name) {
    input.open(file_name, ios::in);
    if (not input.is_open()) {
        cout<<"Error while opening file"<<endl;
        exit(1);
    }
}

void Utils::abrir_archivo(ofstream &output, const string &file_name) {
    output.open(file_name, ios::out);
    if (not output.is_open()) {
        cout<<"Error while opening file"<<endl;
        exit(1);
    }
}
