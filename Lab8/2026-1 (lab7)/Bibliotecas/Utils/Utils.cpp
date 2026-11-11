//
// Created by User on 11/11/2026.
//

#include "Utils.hpp"

void Utils::abrir_archivo(const string &file_name, ifstream &input) {
    input.open(file_name, ios::in);
    if (not input.is_open()) {
        cout<<"Error opening file"<<endl;
        exit(1);
    }
}

void Utils::abrir_archivo(const string &file_name, ofstream &output) {
    output.open(file_name, ios::out);
    if (not output.is_open()) {
        cout<<"Error opening file"<<endl;
        exit(1);
    }
}
