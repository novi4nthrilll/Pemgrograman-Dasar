#include <iostream>
#include <string>
using namespace std;

class Kendaraan {
private:
    string platNomor;
    string jenisKendaraan;   // "Motor" atau "Mobil"
    string merkKendaraan;
    int lamaParkir;

public:
    Kendaraan() {
        platNomor = "";
        jenisKendaraan = "";
        merkKendaraan = "";
        lamaParkir = 0;
    }

    Kendaraan(string platNomor, string jenisKendaraan, string merkKendaraan) {
        this->platNomor = platNomor;
        this->jenisKendaraan = jenisKendaraan;
        this->merkKendaraan = merkKendaraan;
        this->lamaParkir = 0;
    }

    string getPlatNomor() { return platNomor; }
    string getJenisKendaraan() { return jenisKendaraan; }
    int getLamaParkir() { return lamaParkir; }
    void setLamaParkir(int lama) { lamaParkir = lama; }

    void tampilInfo() {
        cout << platNomor << " | " << jenisKendaraan << " | " << merkKendaraan
             << " | " << lamaParkir << " jam" << endl;
    }
};

class KarcisParkir {
private:
    string nomorKendaraan;
    int jamMasuk;
    int jamKeluar;
    string jenisKendaraan;

public:
    KarcisParkir() {
        nomorKendaraan = "";
        jamMasuk = 0;
        jamKeluar = 0;
        jenisKendaraan = "";
    }

    KarcisParkir(string nomorKendaraan, int jamMasuk, int jamKeluar, string jenisKendaraan) {
        this->nomorKendaraan = nomorKendaraan;
        this->jamMasuk = jamMasuk;
        this->jamKeluar = jamKeluar;
        this->jenisKendaraan = jenisKendaraan;
    }

    int hitungDurasi() {
        int durasi = jamKeluar - jamMasuk;
        if (durasi < 1) {
            durasi = 1;  
        }
        return durasi;
    }

    void tampilKarcis() {
        cout << "Karcis " << nomorKendaraan << " | masuk " << jamMasuk
             << ":00 | keluar " << jamKeluar << ":00 | " << jenisKendaraan << endl;
    }
};

class TarifParkir {
private:
    int dendaInap;
    int batasInap;
    int diskonMember;

    int tarifDasar(string jenis) {
        if (jenis == "Motor") {
            return 2000;
        }
        return 5000;
    }

    int tarifLanjut(string jenis) {
        if (jenis == "Motor") {
            return 1000;
        }
        return 2000;
    }

public:
    TarifParkir() {
        dendaInap = 50000;
        batasInap = 24;
        diskonMember = 2000;
    }

    int hitungTarif(string jenis, int jam, bool member) {
        int total = tarifDasar(jenis) + (jam - 1) * tarifLanjut(jenis);
        if (jam > batasInap) {
            total = total + dendaInap;
        }
        if (member) {
            total = total - diskonMember;
            if (total < 0) {
                total = 0;
            }
        }
        return total;
    }
};

class Transaksi {
private:
    Kendaraan kendaraan;
    KarcisParkir karcis;
    bool isMember;
    int totalBiaya;

public:
    Transaksi() {
        isMember = false;
        totalBiaya = 0;
    }

    Transaksi(Kendaraan kendaraan, KarcisParkir karcis, bool isMember, TarifParkir tarif) {
        this->kendaraan = kendaraan;
        this->karcis = karcis;
        this->isMember = isMember;
        
        this->kendaraan.setLamaParkir(karcis.hitungDurasi());
        
        this->totalBiaya = tarif.hitungTarif(this->kendaraan.getJenisKendaraan(),
                                             this->kendaraan.getLamaParkir(), isMember);
    }

    Kendaraan getKendaraan() { return kendaraan; }
    int getTotalBiaya() { return totalBiaya; }
    void setTotalBiaya(int biaya) { totalBiaya = biaya; }

    void tampilTransaksi() {
        kendaraan.tampilInfo();
        karcis.tampilKarcis();
        cout << "Member: " << (isMember ? "Ya" : "Tidak")
             << " | Total: Rp " << totalBiaya << endl;
    }
};

class SistemParkir {
private:
    Transaksi daftarTransaksi[100];
    int jumlahTransaksi;
    int kapasitas;

public:
    SistemParkir() {
        jumlahTransaksi = 0;
        kapasitas = 100;
    }

    void tambahTransaksi(Transaksi t) {
        if (jumlahTransaksi >= kapasitas) {
            cout << "[WARNING] Kapasitas penuh!" << endl;
            return;
        }
        daftarTransaksi[jumlahTransaksi] = t;
        jumlahTransaksi++;
    }

    void tampilRekap() {
        cout << "\nREKAP TRANSAKSI" << endl;
        if (jumlahTransaksi == 0) {
            cout << "Belum ada transaksi." << endl;
            return;
        }
        for (int i = 0; i < jumlahTransaksi; i++) {
            cout << "Transaksi ke-" << (i + 1) << endl;
            daftarTransaksi[i].tampilTransaksi();
            cout << endl;
        }
    }

    
    string keHurufKecil(string s) {
        for (int i = 0; i < s.length(); i++) {
            if (s[i] >= 'A' && s[i] <= 'Z') {
                s[i] = s[i] + 32;
            }
        }
        return s;
    }

    void cariPlat(string cari) {
        for (int i = 0; i < jumlahTransaksi; i++) {
            string plat = daftarTransaksi[i].getKendaraan().getPlatNomor();
            if (keHurufKecil(plat) == keHurufKecil(cari)) {
                cout << "Ditemukan di indeks " << i << endl;
                daftarTransaksi[i].tampilTransaksi();
                return;
            }
        }
        cout << "[INFO] Plat tidak ditemukan." << endl;
    }

    void transaksiTerlama() {
        if (jumlahTransaksi == 0) {
            cout << "Belum ada data." << endl;
            return;
        }
        int idx = 0;
        for (int i = 1; i < jumlahTransaksi; i++) {
            if (daftarTransaksi[i].getKendaraan().getLamaParkir()
                > daftarTransaksi[idx].getKendaraan().getLamaParkir()) {
                idx = i;
            }
        }
        cout << "Terlama : " << daftarTransaksi[idx].getKendaraan().getPlatNomor()
             << " (" << daftarTransaksi[idx].getKendaraan().getLamaParkir() << " jam)" << endl;
    }

    void transaksiTermahal() {
        if (jumlahTransaksi == 0) {
            cout << "Belum ada data." << endl;
            return;
        }
        int idx = 0;
        for (int i = 1; i < jumlahTransaksi; i++) {
            if (daftarTransaksi[i].getTotalBiaya() > daftarTransaksi[idx].getTotalBiaya()) {
                idx = i;
            }
        }
        cout << "Termahal: " << daftarTransaksi[idx].getKendaraan().getPlatNomor()
             << " (Rp " << daftarTransaksi[idx].getTotalBiaya() << ")" << endl;
    }

    int totalPendapatan() {
        int total = 0;
        for (int i = 0; i < jumlahTransaksi; i++) {
            total = total + daftarTransaksi[i].getTotalBiaya();
        }
        return total;
    }

    void diskonMassal(int persen) {
        if (persen < 1 || persen > 100) {
            cout << "[ERROR] Persentase invalid!" << endl;
            return;
        }
        for (int i = 0; i < jumlahTransaksi; i++) {
            int biaya = daftarTransaksi[i].getTotalBiaya();
            daftarTransaksi[i].setTotalBiaya(biaya - biaya * persen / 100);
        }
    }
};

int main() {
    TarifParkir tarif;
    SistemParkir sistem;

    //transaksi 1: motor, 3 jam, member
    Kendaraan k1("N1234AB", "Motor", "Honda Beat");
    KarcisParkir c1("N1234AB", 8, 11, "Motor");
    sistem.tambahTransaksi(Transaksi(k1, c1, true, tarif));

    //transaksi 2: mobil, 5 jam, bukan member
    Kendaraan k2("L5678CD", "Mobil", "Toyota Avanza");
    KarcisParkir c2("L5678CD", 9, 14, "Mobil");
    sistem.tambahTransaksi(Transaksi(k2, c2, false, tarif));

    //yransaksi 3: motor, 2 jam, bukan member
    Kendaraan k3("AB9999XY", "Motor", "Yamaha NMAX");
    KarcisParkir c3("AB9999XY", 10, 12, "Motor");
    sistem.tambahTransaksi(Transaksi(k3, c3, false, tarif));

    sistem.tampilRekap();

    cout << "TERLAMA & TERMAHAL" << endl;
    sistem.transaksiTerlama();
    sistem.transaksiTermahal();

    cout << "\nCARI PLAT" << endl;
    sistem.cariPlat("n1234ab");

    cout << "\nTotal pendapatan: Rp " << sistem.totalPendapatan() << endl;

    cout << "\nDISKON MASSAL 10%" << endl;
    sistem.diskonMassal(10);
    cout << "Total pendapatan setelah diskon: Rp " << sistem.totalPendapatan() << endl;

    return 0;
}