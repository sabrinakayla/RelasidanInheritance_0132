#ifndef IBU_H
#define IBU_H
#include <vector>
#include <string>
#include <iostream>
using namespace std;

class ibu {
public:
    string nama;
    vector<anak*> daftar_anak;

    ibu(string pNama) : nama(pNama) {
        cout << "Ibu \"" << nama << "\" ada\n";
    }

    ~ibu() {
        cout << "Ibu \"" << nama << "\" tidak ada\n";
    }