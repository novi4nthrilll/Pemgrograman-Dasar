#include <stdio.h>

int main() {
    // Decrement: hitung mundur
    int n = 5;
    while (n > 0) {
        printf("%d\n", n); 
        n--;
    } 

    // Increment: menghitung genap
    int jumlahGenap = 0;
    for (int i = 1; i <= 20; i++) {
        if (i % 2 == 0) { 
            jumlahGenap++;
        }
    }
    printf("%d\n", jumlahGenap);
}
