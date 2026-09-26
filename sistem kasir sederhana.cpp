#include <iostream>
#include <string>
using namespace std;

int main(){
	string nama;
	float total;
	int menu;
	int jumlahPembelian;
	int harga;
	int totalPembayaran;
	int diskon;

	cout << "===== KASRI SEDERHANA =====" << endl;
	cout << "1. Nasi Goreng -Rp 15.000" << endl;
	cout << "2. Mie Goreng -Rp 12.000" << endl;
	cout << "3. Ayam Geprek -Rp 18.000" << endl;
	cout << "4. Es teh Anget -Rp 5.000" << endl;
	cout << "Pilih Menu: ";
	cin >> menu;
	cout << "Jumlah Pembelian: ";
	cin >> jumlahPembelian;
	
	switch (menu){
		case 1:
			harga = 15000;
			jumlahPembelian;
			total = harga * jumlahPembelian;
			break;
			
		case 2:
			harga = 12000;
			jumlahPembelian;
			total = harga * jumlahPembelian;
			break;
			
		case 3:
			harga = 18000;
			jumlahPembelian;
			total = harga * jumlahPembelian;
			break;
			
		case 4:
			harga = 5000;
			jumlahPembelian;
			total = harga * jumlahPembelian;
			break;
			
		default:
			cout << "Lu niat belanja ga sih, ga usah dateng lagi deh" << endl;
	} 
	
	if (total >= 50000){
		diskon = total * 0.1;
		totalPembayaran = total - diskon;
	} else if(total >= 30000){
		diskon = total * 0.05;
		totalPembayaran = total - diskon;
	} else if(total < 30000){
		diskon = 0;
	}
	//cout<< "harga makanan" << totalPembayaran;
	
	cout << "===== STRUK PEMBELIAN =====" << endl;
	cout << "Harga : Rp " << harga << endl;
	cout << "Jumlah : " << jumlahPembelian << endl;
	cout << "Total : Rp" << total << endl;
	cout << "Diskon (10%) : Rp" << diskon << endl;
	cout << "Total Bayar : Rp " << totalPembayaran << endl;
	cout << "==========================" << endl;
	return 0;
}
