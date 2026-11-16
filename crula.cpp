#include <iostream>
using namespace std;

double olla(int a, int b){
    double tambah = a + b;
    return tambah;
    double kurang = a - b;
    return kurang;
    double kali = a * b;
    return kali;
    double bagi = a / b;
    return bagi;
}

int main(){
    cout << "Hasil penjumlahan: " << olla(5, 10) << endl;
    cout << "Hasil Pengurangan: " << olla(5, 10) << endl;
    cout << "Hasil Perkalian: " << olla(5, 10) << endl;
    cout << "Hasil Pembagian: " << olla(5, 10) << endl;
    return 0;
}