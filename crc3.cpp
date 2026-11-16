#include <iostream>
using namespace std;

// // 1. Class Kendaraan
// class Kendaraan {
// private:
//     int jenis;
//     int lamaParkir;
// public:
//     void setData(int j, int l) { jenis = j; lamaParkir = l; }
//     int getJenis() { return jenis; }
//     int getLamaParkir() { return lamaParkir; }
// };

// // 2. Class Civitas
// class Civitas {
// private:
//     bool isMember;
// public:
//     void setStatus(bool m) { isMember = m; }
//     bool getStatus() { return isMember; }
// };

// // 3. Class KalkulatorParkir
// class KalkulatorParkir {
// private:
//     int tarifMotor = 2000;
//     int tarifMobil = 5000;
//     int dendaLebih24Jam = 50000;
//     int potonganMember = 2000;
// public:
//     int hitungTotal(Kendaraan k, Civitas c) {
//         int total = 0;
//         if (k.getJenis() == 1) {
//             total = tarifMotor + (k.getLamaParkir() - 1) * 1000;
//         } else if (k.getJenis() == 2) {
//             total = tarifMobil + (k.getLamaParkir() - 1) * 2000;
//         } else {
//             return -1; // Error / Anomali
//         }
        
//         if (k.getLamaParkir() > 24) total += dendaLebih24Jam;
//         if (c.getStatus()) total -= potonganMember;
//         if (total < 0) total = 0;
//         return total;
//     }
// };

// // 4. Class SistemParkir (View)
// class SistemParkir {
// public:
//     void tampilkanError() {
//         cout << "who?? ALERTTTT ANOMALI DETECTED!!!!!" << endl;
//     }

//     void jalankanProgram() {
//         int menu, lama; bool member;
        
//         cout << "silahkan memilih '1' untuk motor dan '2' untuk mobil" << endl;
//         cin >> menu;
//         cout << "berapa lama anda parkir di smart brawijaya?" << endl;
//         cin >> lama;
//         cout << "apakah anda seorang civitas akademik (1 = Ya, 0 = Tidak)" << endl;
//         cin >> member;

//         Kendaraan kdr; kdr.setData(menu, lama);
//         Civitas cvt;   cvt.setStatus(member);
//         KalkulatorParkir kalkulator;

//         int total = kalkulator.hitungTotal(kdr, cvt);
        
//         if (total != -1) {
//             cout << "Berikut besaran biaya parkir anda: " << total << endl;
//         } else {
//             tampilkanError();
//         }
//     }
// };

class Barang {
    private:
        string kodeBarang, namaBarang;
        double harga;
    public:
        Barang(string kode, string nama, double harga): kodeBarang(kode), namaBarang(nama), harga(harga) {}
        string getKodeBarang() { return kodeBarang; }
        string getNamaBarang() { return namaBarang; }
        double getHarga() { return harga; }

    void tampilkan_data(){
        cout << kodeBarang << endl;
        cout << namaBarang << endl;
        cout << harga << endl;
    }
};

class ItemTransaksi {
    private:
        Barang* barang;
        int jumlahBeli;
    public:
        ItemTransaksi(Barang* barang, int jumlahBeli): barang(barang), jumlahBeli(jumlahBeli) {}
        double hitungSubtotal() {
            return barang->getHarga() * jumlahBeli;
        }
        Barang* getBarang() { return barang; }
        int getJumlahBeli() { return jumlahBeli; }

    void tampilkanBarisStruk() {
    cout << barang->getKodeBarang() << " | "
         << barang->getNamaBarang() << " | "
         << barang->getHarga() << " x "
         << jumlahBeli << " = Rp "
         << hitungSubtotal() << endl;
    }
};

int main() {
    int kapasitas;
    cout << "Jumlah jenis barang: ";
    cin >> kapasitas;
    cin.ignore();

    ItemTransaksi** keranjangBelanja =
        new ItemTransaksi*[kapasitas]();

    for (int i = 0; i < kapasitas; i++){
        string kode, nama;
        double harga;
        int jumlah;
// kode, nama, harga, jumlah dibaca dari cin/getline
        Barang* produk = new Barang(kode, nama, harga);
        keranjangBelanja[i] = new ItemTransaksi(produk, jumlah);
    }
    // SistemParkir app;
    // app.jalankanProgram();
    // return 0;
    Barang* daftar[] = {
        new Barang("B01", "Buku Tulis", 5000),
        new Barang("B02", "Pensil 2B", 3000),
        new Barang("B03", "Penghapus", 1500)
    };

    for(int i = 0; i < 3; i++){
        // daftar[i] -> tampilkan_data();
        cout << daftar[i] -> getKodeBarang() << endl;
        cout << daftar[i] -> getNamaBarang() << endl;
    }

    double totalBelanja = 0;
    
    for (int i = 0; i < kapasitas; i++) {
        ItemTransaksi* item = keranjangBelanja[i];
        if (item != nullptr) {
            item->tampilkanBarisStruk();
            totalBelanja += item->hitungSubtotal();
        }
    }
    
    cout << "Total: Rp " << totalBelanja << endl;
}