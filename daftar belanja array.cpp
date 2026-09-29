#include <iostream>
#include <string>
using namespace std;

int main(){
	string daftarBelanja[5] = {"Beras", "Minyak Goreng", "Telur", "Ayam", "Susu"};
	
//	daftarBelanja[0] = "Beras";
//	daftarBelanja[1] = "Minyak Goreng";
//	daftarBelanja[2] = "Telur";
//	daftarBelanja[3] = "Ayam";
//	daftarBelanja[4] = "Susu";
	
	cout << "Daftar Belanjaan:" << endl;
	
	for (int i = 0; i<5; i++){
		 cout << daftarBelanja[i] << endl;
	}
	
//	cout << daftarBelanja[0] << endl;
//	cout << daftarBelanja[1] << endl;
//	cout << daftarBelanja[2] << endl;
//	cout << daftarBelanja[3] << endl;
//	cout << daftarBelanja[4] << endl;

	return 0;
}
