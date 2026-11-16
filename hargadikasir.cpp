#include <iostream>
using namespace std;

int olla = 999999999;

int bayar(int harga) {
    olla = 1000000000;
    cout << "olla: " << olla << endl;
    return harga;
}

int bayar(int harga, int jumlah) {
    return harga * jumlah;
}

int bayar(int harga, int jumlah, int persen) {
    int total = harga * jumlah;
    return total - total * persen / 100;
}

double bayar(double harga) {
    return harga;
}

int main(){
    cout << bayar(15000) << endl;
    cout << bayar(15000, 3) << endl;
    cout << bayar(15000, 3, 10) << endl;
    cout << bayar(15000.50) << endl;
    cout << olla << endl;
}