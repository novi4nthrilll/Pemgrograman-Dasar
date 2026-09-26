#include <stdio.h>

int main(){
	const int THRESHOLD = 75;
	int jumlah = 0;
	int totalLoop = 0;
	for (int i = 0; i< 100; i++) {
		if (jumlah > THRESHOLD) {
			break;
	}
	
	jumlah += i;
	totalLoop++;
	}
	
	printf("Banyak iterasi = %d\n", totalLoop);
	printf("Jumlah = %d\n", jumlah);
	return 0;
}
