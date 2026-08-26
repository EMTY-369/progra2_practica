#include <iostream>
using namespace std;

int main() {
    int code = 25;

    int *ptr_code = &code;

    cout << "code:      " << code << endl;
    cout << "&code:     " << &code << endl;
    cout << "ptrCode:   " << ptr_code << endl;
    cout << "*ptrCode:  " << *ptr_code << endl<<endl;

    *ptr_code = 100;

    cout << "code:      " << code << endl;
    cout << "*ptrCode:  " << *ptr_code << endl;
    cout << "&code:     " << &code << endl;
    cout << "ptrCode:   " << ptr_code << endl;
    return 0;
}
