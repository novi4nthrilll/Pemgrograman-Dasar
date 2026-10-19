#include <iostream>
using namespace std;

int totalHarga(const int harga[], int n) {
	int total = 0;
	for (int i = 0; i < n; i++) {
		total += harga[i];
	}
	return total;
	}
	
void diskon(int harga[], int n, int persen) {
	for (int i = 0; i < n; i++) {
		harga[i] -= harga[i] * persen / 100;
	}
}

int main(){
	int harga[6];
	int keranjang[] = {15000, 8500, 22000};
	cout << totalHarga(keranjang, 3) << endl;
	diskon(keranjang, 3, 10);
	cout << totalHarga(keranjang, 3) << endl;
}
