#include <iostream>
using namespace std;

int bayar(int harga) {
    return harga;
}

int bayar(int harga, int jumlah) {
    return harga * jumlah;
}

int bayar(int harga, int jumlah, int persen) {
    int total = harga * jumlah;
    return total - total * persen / 100;
}

int main(){
    cout << bayar(15000) << endl;
    cout << bayar(15000, 3) << endl;
    cout << bayar(15000, 3, 10) << endl;
}