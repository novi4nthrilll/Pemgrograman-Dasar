#include <iostream>
#include <string>

using namespace std;

int main() {
    string nama[20];
    int golongan[20];
    int lembur[20];
    int absen[20];
    long long gajiBersih[20];
    string status[20];

    int jumlahKaryawan = 0;

    do {
        cout << "Jumlah karyawan (1-20): ";
        cin >> jumlahKaryawan;

        if (jumlahKaryawan < 1 || jumlahKaryawan > 20) {
            cout << "Input tidak valid! Masukkan angka 1 sampai 20.\n";
        }
    } while (jumlahKaryawan < 1 || jumlahKaryawan > 20);

    for (int i = 0; i < jumlahKaryawan; i++) {
        cout << "Karyawan " << (i + 1) << " - Nama     : ";
        cin >> nama[i];

        do {
            cout << "Karyawan " << (i + 1) << " - Golongan : ";
            cin >> golongan[i];
            if (golongan[i] < 1 || golongan[i] > 3) {
                cout << "Golongan harus 1, 2, atau 3!\n";
            }
        } while (golongan[i] < 1 || golongan[i] > 3);

        do {
            cout << "Karyawan " << (i + 1) << " - Lembur   : ";
            cin >> lembur[i];
            if (lembur[i] < 0) {
                cout << "Jam lembur tidak boleh negatif!\n";
            }
        } while (lembur[i] < 0);

        do {
            cout << "Karyawan " << (i + 1) << " - Absen    : ";
            cin >> absen[i];
            if (absen[i] < 0 || absen[i] > 26) {
                cout << "Absen harus 0 sampai 26 hari!\n";
            }
        } while (absen[i] < 0 || absen[i] > 26);
    }

    for (int i = 0; i < jumlahKaryawan; i++) {
        long long gajiPokok = 0;
        if (golongan[i] == 1) {
            gajiPokok = 4000000;
        } else if (golongan[i] == 2) {
            gajiPokok = 6000000;
        } else {
            gajiPokok = 8000000;
        }

        long long upahLembur = lembur[i] * 30000LL;
        long long potongan = absen[i] * 150000LL;
        gajiBersih[i] = gajiPokok + upahLembur - potongan;

        if (absen[i] == 0) {
            status[i] = "TELADAN";
        } else if (absen[i] <= 3) {
            status[i] = "BAIK";
        } else {
            status[i] = "PEMBINAAN";
        }
    }

    cout << "\nNo\tNama\tGol\tGaji Bersih\tStatus\n";

    for (int i = 0; i < jumlahKaryawan; i++) {
        cout << (i + 1) << "\t"
             << nama[i] << "\t"
             << golongan[i] << "\t"
             << gajiBersih[i] << "\t\t"
             << status[i] << endl;
    }

    return 0;
}
