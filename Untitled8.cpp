#include <iostream>
using namespace std;

int main(){
	bool member;
	int totalBelanja;
	int totalBayar;
	int potongan = 0;
	
	cout << "masukkan total belanja anda" << endl;
	cin >> totalBelanja;
	
	cout << "apakah anda memiliki kartu member? (masukkan 1 untuk 'Ya' dan 0 untuk 'Tidak')" << endl;
	cin >> member;
	
	if (member == 1 && totalBelanja >= 500000){
		potongan = 0.1 * totalBelanja;
		cout << "selamat anda mendapatkan potongan sebesar: " << potongan << endl;
	} 
	totalBayar = totalBelanja - potongan;
	cout << "silahkan bayar dengan harga sekian " << totalBayar << endl;
	
	return 0;
}
