#include <stdio.h>

int main() {
    int jumlahMotor = 0, jumlahMobil = 0;
    int totalParkirMotor = 0, totalParkirMobil = 0;
    int totalJamMotor = 0, totalJamMobil = 0;
    int maxJamMotor = 0, maxBiayaMotor = 0;
    int maxJamMobil = 0, maxBiayaMobil = 0;
    int jenisKendaraan = 0;

    do {
        printf("Masukkan jenis kendaraan (1=motor, 2=mobil, 0=Keluar): ");
        scanf("%d", &jenisKendaraan);

        if (jenisKendaraan == 0) {
            break;
        } else if (jenisKendaraan != 1 && jenisKendaraan != 2) {
            printf("Jenis kendaraan salah. Ulangi kembali\n");
            continue;
        }

        int jam, member;
        printf("Masukkan lama parkir (dalam jam): ");
        scanf("%d", &jam);

        if (jam <= 0) {
            printf("Error!\n");
            continue;
        }

        printf("Civitas akademik? (1=Ya, 0=Tidak): ");
        scanf("%d", &member);

        int tarifDasar, tarifLanjut, jumlah;
        const char *kendaraan;

        if (jenisKendaraan == 1) {
            tarifDasar = 2000; tarifLanjut = 1000;
            kendaraan = "motor";
            jumlahMotor++;
            jumlah = jumlahMotor;
        } else {
            tarifDasar = 5000; tarifLanjut = 2000;
            kendaraan = "mobil";
            jumlahMobil++;
            jumlah = jumlahMobil;
        }

        int tarif = tarifDasar + (jam - 1) * tarifLanjut;
        if (jam > 24) tarif += 50000;      
        if (member == 1) tarif -= 2000;   
        if (tarif < 0) tarif = 0;

        if (jenisKendaraan == 1) {
            totalParkirMotor += tarif;
            totalJamMotor += jam;
            if (jam > maxJamMotor) { maxJamMotor = jam; maxBiayaMotor = tarif; }
        } else {
            totalParkirMobil += tarif;
            totalJamMobil += jam;
            if (jam > maxJamMobil) { maxJamMobil = jam; maxBiayaMobil = tarif; }
        }

        printf("Total biaya parkir %s-%d = %d\n", kendaraan, jumlah, tarif);

    } while (jenisKendaraan != 0);

    printf("Jumlah motor = %d\n", jumlahMotor);
    printf("Total biaya parkir motor = %d\n", totalParkirMotor);
    printf("Jumlah mobil = %d\n", jumlahMobil);
    printf("Total biaya parkir mobil = %d\n", totalParkirMobil);

    double rataMotor = jumlahMotor > 0 ? (double)totalJamMotor / jumlahMotor : 0;
    double rataMobil = jumlahMobil > 0 ? (double)totalJamMobil / jumlahMobil : 0;
    printf("Rata-rata lama parkir motor = %.2f jam\n", rataMotor);
    printf("Rata-rata lama parkir mobil = %.2f jam\n", rataMobil);

    printf("Parkir motor paling lama = %d jam dengan biaya parkir = %d\n", maxJamMotor, maxBiayaMotor);
    printf("Parkir mobil paling lama = %d jam dengan biaya parkir = %d\n", maxJamMobil, maxBiayaMobil);

    return 0;
}
