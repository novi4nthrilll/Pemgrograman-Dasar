#include <stdio.h>
#include <string.h>
#define MAX_TRANSAKSI 10

int main() {
    char platNomor[MAX_TRANSAKSI][20];
    char jenisKendaraanStr[MAX_TRANSAKSI][10];
    int lamaParkir[MAX_TRANSAKSI];
    int totalBiaya[MAX_TRANSAKSI];
    int jumlahTransaksi = 0;

    int slotParkir[3][4] = {
        {1, 0, 1, 0},
        {0, 1, 1, 0},
        {0, 0, 0, 1}
    };

    int menu = 0;

    do {
        printf("\n=== SISTEM SMART BRAWIJAYA PARKIR V3 ===\n");
        printf("1. Input Transaksi Parkir Keluar\n");
        printf("2. Tampilkan Rekap & Riwayat Transaksi (Array 1D)\n");
        printf("3. Cari Transaksi Parkir Paling Lama & Mahal\n");
        printf("4. Cari Transaksi berdasarkan Plat Nomor (Linear Search)\n");
        printf("5. Lihat Denah Slot Parkir Kampus (Array 2D)\n");
        printf("0. Keluar\n");
        printf("Pilih Menu: ");
        scanf("%d", &menu);

        switch (menu) {

        case 1: {
            if (jumlahTransaksi >= MAX_TRANSAKSI) {
                printf("[WARNING] Kapasitas memori riwayat transaksi penuh!\n");
                break;
            }

            char plat[20];
            int jenis, jam;
            printf("Masukkan Plat Nomor (contoh: N1234AB): ");
            scanf("%19s", plat);
            printf("Masukkan Jenis Kendaraan (1=Motor, 2=Mobil): ");
            scanf("%d", &jenis);
            printf("Masukkan Lama Parkir (jam): ");
            scanf("%d", &jam);

            if (jam <= 0 || (jenis != 1 && jenis != 2)) {
                printf("[ERROR] Input jenis kendaraan atau lama parkir invalid!\n");
                break;
            }

            int total;
            int tarifDasar = (jenis == 1) ? 2000 : 5000;
            int tarifLanjut = (jenis == 1) ? 1000 : 2000;
            int denda = (jam > 24) ? 50000 : 0;
            if (jam == 1) {
                total = tarifDasar + denda;
            } else {
                total = tarifDasar + ((jam - 1) * tarifLanjut) + denda;
            }

            strcpy(platNomor[jumlahTransaksi], plat);
            strcpy(jenisKendaraanStr[jumlahTransaksi], (jenis == 1) ? "Motor" : "Mobil");
            lamaParkir[jumlahTransaksi] = jam;
            totalBiaya[jumlahTransaksi] = total;

            printf("--> Transaksi Berhasil Disimpan di Indeks [%d]! Total Biaya: Rp %d\n",
                   jumlahTransaksi, total);
            jumlahTransaksi++;
            break;
        }

        case 2:
            printf("\n--- REKAP RIWAYAT TRANSAKSI ---\n");
            if (jumlahTransaksi == 0) {
                printf("Belum ada transaksi recorded.\n");
            } else {
                printf("%-5s %-12s %-10s %-10s %-12s\n",
                       "No", "Plat Nomor", "Jenis", "Lama(Jam)", "Total Biaya");
                for (int i = 0; i < jumlahTransaksi; i++) {
                    printf("%-5d %-12s %-10s %-10d Rp %-10d\n", (i + 1), platNomor[i],
                           jenisKendaraanStr[i], lamaParkir[i], totalBiaya[i]);
                }
            }
            break;

        case 3: {
            if (jumlahTransaksi == 0) {
                printf("Belum ada data transaksi.\n");
                break;
            }
            int maxJam = lamaParkir[0];
            int maxBiaya = totalBiaya[0];
            int idxMax = 0;
            for (int i = 1; i < jumlahTransaksi; i++) {
                if (lamaParkir[i] > maxJam) {
                    maxJam = lamaParkir[i];
                    maxBiaya = totalBiaya[i];
                    idxMax = i;
                }
            }
            printf("\n--- KENDARAAN PARKIR TERLAMA ---\n");
            printf("Plat Nomor  : %s (%s)\n", platNomor[idxMax], jenisKendaraanStr[idxMax]);
            printf("Lama Parkir : %d Jam\n", maxJam);
            printf("Total Biaya : Rp %d\n", maxBiaya);
            break;
        }

        case 4: {
            if (jumlahTransaksi == 0) {
                printf("Belum ada data transaksi.\n");
                break;
            }
            char cari[20];
            int ditemukan = 0;
            printf("Masukkan plat nomor yang dicari: ");
            scanf("%19s", cari);

            for (int i = 0; i < jumlahTransaksi; i++) {
                if (strcmp(platNomor[i], cari) == 0) {   // 0 = sama
                    printf("Ditemukan di indeks [%d]: %s | %s | %d jam | Rp %d\n",
                           i, platNomor[i], jenisKendaraanStr[i],
                           lamaParkir[i], totalBiaya[i]);
                    ditemukan = 1;
                }
            }
            if (!ditemukan) {
                printf("Plat %s tidak ditemukan.\n", cari);
            }
            break;
        }

        case 5: {
            printf("\n--- DENAH SLOT PARKIR KAMPUS (3x4) ---\n");
            printf("[0 = Kosong/Tersedia | 1 = Terisi]\n");
            int slotKosong = 0;
            for (int b = 0; b < 3; b++) {
                printf("Lantai/Baris %d : | ", b);
                for (int c = 0; c < 4; c++) {
                    printf("%d | ", slotParkir[b][c]);
                    if (slotParkir[b][c] == 0) slotKosong++;
                }
                printf("\n");
            }
            printf("Sisa Slot Parkir Kosong: %d Slot\n", slotKosong);
            break;
        }

        case 0:
            printf("Terima kasih telah menggunakan Sistem Smart Brawijaya 3.\n");
            break;

        default:
            printf("Pilihan menu tidak valid!\n");
        }

    } while (menu != 0);

    return 0;
}
