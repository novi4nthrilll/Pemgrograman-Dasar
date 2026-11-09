#include <iostream>
#include <string>
using namespace std;

class Dokumen {
    private:
        string judul;
        int jumlahHalaman;
        int rangkap;
        bool tercetak;
    public:
        Dokumen(string judul, int jumlahHalaman, int rangkap) {
            this->judul = judul;
            this->jumlahHalaman = (jumlahHalaman > 0) ? jumlahHalaman : 1;
            this->rangkap = (rangkap > 0) ? rangkap : 1;
            tercetak = false;
        }

    int hitungLembar() const { return jumlahHalaman * rangkap; }
    void tandaiTercetak() { tercetak = true; }
    bool isTercetak() const { return tercetak; }
    string getJudul() const { return judul; }
};

class Printer {
    private:
        string nama;
        int sisaKertas;
    public:
        Printer(string nama, int sisaKertas) {
            this->nama = nama;
            this->sisaKertas = (sisaKertas > 0) ? sisaKertas : 0;
        }
    
    bool cetak(Dokumen& dok) { // &: dokumen asli
    int lembar = dok.hitungLembar(); // pesan 1 ke dok
    if (lembar > sisaKertas) return false; // kertas kurang
        sisaKertas -= lembar;
        dok.tandaiTercetak(); // pesan 2 ke dok
    return true;
}
    string getNama() const { return nama; }
    int getSisaKertas() const { return sisaKertas; }
};

int main() {
    Printer printerLab("Lab Dasar", 50);
    Dokumen laporan("Laporan Praktikum", 12, 3);
    Dokumen poster("Poster Kegiatan", 1, 20);
    bool ok1 = printerLab.cetak(laporan);
    bool ok2 = printerLab.cetak(poster);
    cout << laporan.getJudul() << ": " << (ok1 ? "tercetak" : "ditolak") << endl;
    cout << poster.getJudul() << ": " << (ok2 ? "tercetak" : "ditolak") << endl;
    cout << "Sisa kertas " << printerLab.getNama() << ": " << printerLab.getSisaKertas() << endl;
return 0;
}