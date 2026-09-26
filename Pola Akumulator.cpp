#include <stdio.h>

int main() {
int total = 0;
	for (int i = 1; i <= 10; i+= 2) {
		printf("Penjumlahan: %d\n", i);
		total = total + i;
	}
	printf("Total: %d\n", total);
	return 0;
}

