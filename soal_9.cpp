#include<iostream>
using namespace std;

class BukuTulis{
    public:
        int jumlahLembar;
        int kataPerHari;
        double halamanPerHari;
        double lamaHari;
        BukuTulis();
        BukuTulis(int lembar, int kata, double halaman);
        void hitungLamaHari();
        void displayMessage();
    };

BukuTulis::BukuTulis(){
    jumlahLembar = 50;
    kataPerHari = 100;
    halamanPerHari = 0.5;
    lamaHari = 0.0;
}

BukuTulis::BukuTulis(int lembar, int kata, double halaman){
    jumlahLembar = lembar;
    kataPerHari = kata;
    halamanPerHari = halaman;
    lamaHari = 0.0;
}

void BukuTulis::hitungLamaHari(){
    lamaHari = (jumlahLembar * 2) / halamanPerHari;
}

void BukuTulis::displayMessage(){
    cout << "----------------------------------------" << endl;
    cout << "Jumlah Lembar\t\t: " << jumlahLembar << " lembar" << endl;
    cout << "Kata per Hari\t\t: " << kataPerHari << " kata" << endl;
    cout << "Halaman per Hari\t: " << halamanPerHari << " halaman" << endl;
    cout << "Total Halaman\t\t: " << jumlahLembar * 2 << " halaman" << endl;
    cout << "Lama Hari\t\t: " << lamaHari << " hari" << endl;
    cout << "----------------------------------------" << endl;
}

int main(){
    BukuTulis buku_a;
    buku_a.hitungLamaHari();
    buku_a.displayMessage();

    BukuTulis buku_b(100, 200, 1.0);
    buku_b.hitungLamaHari();
    buku_b.displayMessage();

    return 0;
}