#include <stdio.h>

int main() {
    int data = 0;
    int total = 0;
    int jumlahData = 0;
    
    for (int i = 0; i < 5; i++) {
        printf("%d: ", i + 1);
        scanf("%d", &data); // Perbaikan: tambah &
        total = total + data;
        jumlahData++;
    }
    
    float rerata = (float) total / jumlahData;
    printf("Rata-rata: %.2f\n", rerata);
    
    return 0;
}

