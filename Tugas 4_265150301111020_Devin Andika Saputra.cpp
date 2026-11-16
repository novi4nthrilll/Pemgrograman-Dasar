#include <iostream>
#include <string>
#include <stdio.h>
#include <algorithm>
#include <cctype>           // ternyata butuh ini T_T
using namespace std;

const int BATAS_INAP   = 24;
const int DENDA_INAP   = 50000;
const int DISKON_MEMBER = 2000;
const int KAPASITAS    = 100;
const int KOLOM        = 5;
const int BARIS        = 3;   

// prosedur dengan parameter: mencetak garis sepanjang n
void cetakGaris(int n) {
    for (int i = 0; i < n; i++) {
        cout << "-";
    }
cout << endl;
}

// prosedur tanpa parameter: menampilkan menu utama
void tampilMenu() {
    cout << "\n=== SISTEM SMART BRAWIJAYA PARKIR V4 ===" << endl;
    cout << "1. Input Transaksi Parkir Keluar" << endl;
    cout << "2. Rekap dan riwayat" << endl;
    cout << "3. Terlama dan termahal" << endl;
    cout << "4. Cari plat nomor" << endl;
    cout << "5. Denah slot parkir" << endl;
    cout << "6. Statistik pendapatan" << endl;
    cout << "7. Promo diskon massal" << endl;
    cout << "8. Simulasi tarif" << endl;
    cout << "0. Keluar" << endl;
    cout << "Pilih Menu: ";
}


bool inputValid(int jenis, int jam) {
    return jam > 0 && (jenis == 1 || jenis == 2);
}
string namaJenis(int jenis) {
    return (jenis == 1) ? "Motor" : "Mobil";
}
int tarifDasar(int jenis) {
    return (jenis == 1) ? 2000 : 5000;
}
int tarifLanjut(int jenis) {
    return (jenis == 1) ? 1000 : 2000;
}

// versi 1: tanpa status member
int hitungTarif(int jenis, int jam) {
    int denda = (jam > BATAS_INAP) ? DENDA_INAP : 0;
    return tarifDasar(jenis)
        + (jam - 1) * tarifLanjut(jenis) + denda;
}

// versi 2: dengan status member
int hitungTarif(int jenis, int jam, bool member) {
    int total = hitungTarif(jenis, jam);
        return member ? max(0, total - DISKON_MEMBER) : total;
}

int inputTransaksi(istream &in, string plat[], string jenisStr[],
int lama[], int biaya[], int n) {
    if (n >= KAPASITAS) {
    cout << "[WARNING] Kapasitas memori riwayat transaksi penuh!" << endl;
    return n;
    }

    string p; int jenis, jam, member;
    cout << "Masukkan Plat Nomor (contoh: N1234AB): ";
    getline(in, p);
    cout << "Masukkan Jenis Kendaraan (1=Motor, 2=Mobil): ";
    in >> jenis;
    cout << "Masukkan Lama Parkir (jam): ";
    in >> jam;
    cout << "Member civitas akademika? (1=Ya, 0=Tidak): ";
    in >> member;
    in.ignore(1000, '\n');
    if (!inputValid(jenis, jam)) {
    cout << "[ERROR] Input jenis kendaraan atau lama parkir invalid!" << endl;
    return n;
    }

    int total = hitungTarif(jenis, jam, member == 1);
    plat[n] = p;
    jenisStr[n] = namaJenis(jenis);
    lama[n] = jam;
    biaya[n] = total;
    printf("--> Transaksi Berhasil Disimpan di Indeks [%d]! Total Biaya: Rp %d\n", n, total);
    return n + 1;
}

int catat(int n) {
    return n + 1;
}

void tampilRekap(string plat[], string jenisStr[], int lama[], int biaya[], int n) {
    cout << "\n--- REKAP RIWAYAT TRANSAKSI ---" << endl;
    if (n == 0) {
        cout << "Belum ada transaksi recorded." << endl;
        return;
    }
    printf("%-5s %-12s %-10s %-10s %-12s\n", "No", "Plat Nomor", "Jenis", "Lama(Jam)", "Total Biaya");
    cetakGaris(52);
    for (int i = 0; i < n; i++) {
        printf("%-5d %-12s %-10s %-10d Rp %-10d\n", i + 1, plat[i].c_str(), jenisStr[i].c_str(), lama[i], biaya[i]);
    }
}

int indeksMaks(int data[], int n) {
    if (n == 0) return -1;   
    int idx = 0;
    for (int i = 1; i < n; i++) {
        if (data[i] > data[idx]) {
        idx = i;
    }
}

return idx;

}

int cariPlat(string plat[], int n, string cari) {
    for (int i = 0; i < n; i++) {
        string a = plat[i], b = cari;
        for (auto &c : a) c = tolower(c);
        for (auto &c : b) c = tolower(c);
        if (a == b) return i;
    }
    return -1;
}

int hitungSlotKosong(int slot[][KOLOM], int baris) {
    int kosong = 0;
    for (int b = 0; b < baris; b++) {
        for (int c = 0; c < KOLOM; c++) {
            if (slot[b][c] == 0) kosong++;
        }
    }
    return kosong;
}

void tampilDenah(int slot[][KOLOM], int baris) {
    cout << "\n--- DENAH SLOT PARKIR KAMPUS (" << baris << "x" << KOLOM << ") ---" << endl;
    cout << "[0 = Kosong/Tersedia | 1 = Terisi]" << endl;
    for (int b = 0; b < baris; b++) {
        cout << "Lantai/Baris " << b << " : | ";
        for (int c = 0; c < KOLOM; c++) {
            cout << slot[b][c] << " | ";
        }
    cout << endl;
    }
    cout << "Sisa Slot Parkir Kosong: " << hitungSlotKosong(slot, baris) << " Slot" << endl;
}

int totalPendapatan(int biaya[], int n) {
    int total = 0;
    for (int i = 0; i < n; i++) {
        total += biaya[i];
    }
    return total;
}

int totalPendapatan(string jenisStr[], int biaya[], int n, string jenis) {
    int total = 0;
    for (int i = 0; i < n; i++) {
        if (jenisStr[i] == jenis) total += biaya[i];
    }
    return total;
}

int totalPendapatanRek(int biaya[], int n) {
    if (n == 0) {
        return 0; // kasus dasar
    }
    return biaya[n - 1] + totalPendapatanRek(biaya, n - 1);
}

void diskonMassal(int biaya[], int n, int persen) {
    for (int i = 0; i < n; i++) {
        biaya[i] -= biaya[i] * persen / 100;
    }
}

// pemanggil di main(), case 7
int biayaJamRek(int jenis, int jam) {
    if (jam <= 1) {                    
        return tarifDasar(jenis);
    }
    return tarifLanjut(jenis) + biayaJamRek(jenis, jam - 1);
}

void cetakRincianJam(int jenis, int jam) {
    if (jam <= 0) {                    
        return;
    }
    cetakRincianJam(jenis, jam - 1);
    int biaya = (jam == 1) ? tarifDasar(jenis) : tarifLanjut(jenis);
    printf("Jam ke-%d : Rp %d\n", jam, biaya);
}

int main() {
    string platNomor[KAPASITAS];
    string jenisKendaraanStr[KAPASITAS];
    int    lamaParkir[KAPASITAS];
    int    totalBiaya[KAPASITAS];
    int    slotParkir[BARIS][KOLOM] = {0};
    int    jumlahTransaksi = 0;
    int    menu;


    do {
        tampilMenu();
        cin >> menu; cin.ignore(1000, '\n');
        switch (menu) {
            case 1: jumlahTransaksi = inputTransaksi(cin, platNomor, jenisKendaraanStr, lamaParkir, totalBiaya, jumlahTransaksi); break;
            case 2: tampilRekap(platNomor, jenisKendaraanStr, lamaParkir, totalBiaya, jumlahTransaksi); break;
            case 3: {
                int iLama  = indeksMaks(lamaParkir, jumlahTransaksi);
                int iMahal = indeksMaks(totalBiaya, jumlahTransaksi);
                if (jumlahTransaksi > 0) {
                    cout << "Terlama : " << platNomor[iLama] << " (" << lamaParkir[iLama] << " jam)" << endl;
                    cout << "Termahal: " << platNomor[iMahal] << " (Rp " << totalBiaya[iMahal] << ")" << endl;
                } else {
                    cout << "Belum ada data." << endl;
                }
                break;
            }

            case 4: {
                cout << "Masukkan plat yang dicari: ";
                string cari; getline(cin, cari);
                int idx = cariPlat(platNomor, jumlahTransaksi, cari);
                if (idx == -1) cout << "[INFO] Plat tidak ditemukan." << endl;
                else printf("Ditemukan di indeks %d: %s\n", idx, platNomor[idx].c_str());
                break;
            }

            case 5: tampilDenah(slotParkir, BARIS); break;

            case 6: {
                cout << "Total keseluruhan : Rp " << totalPendapatan(totalBiaya, jumlahTransaksi) << endl;
                cout << "Total Motor       : Rp " << totalPendapatan(jenisKendaraanStr, totalBiaya, jumlahTransaksi, "Motor") << endl;
                cout << "Total Mobil       : Rp " << totalPendapatan(jenisKendaraanStr, totalBiaya, jumlahTransaksi, "Mobil") << endl;
                break;
            }

            case 7: {
                int persen;
                cout << "Masukkan persen diskon (1-100): ";
                cin >> persen; cin.ignore(1000, '\n');
                if (persen < 1 || persen > 100) {
                    cout << "[ERROR] Persentase invalid!" << endl;
                } else {
                    diskonMassal(totalBiaya, jumlahTransaksi, persen);
                }
                break;
            }

            case 8: {
                int jenis, jam;
                cout << "Jenis (1=Motor,2=Mobil): "; cin >> jenis;
                cout << "Lama (jam): ";              cin >> jam;
                cin.ignore(1000, '\n');
                if (!inputValid(jenis, jam)) { cout << "[ERROR] Input invalid!" << endl; break; }
                cetakRincianJam(jenis, jam);
                cout << "Total (rekursif): Rp " << biayaJamRek(jenis, jam) << endl;
                break;
            }

            case 0: cout << "Terima kasih telah menggunakan smart parking brawijaya mark iv!!!" << endl; break;
            default: cout << "Pilihan menu tidak valid!" << endl;
        }
    } while (menu != 0);

    return 0; 
}