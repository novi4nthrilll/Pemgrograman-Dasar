#include <iostream>
using namespace std;

int main (){
	int belanja;
	
	cout << "masukkan harga belanjaan anda" << endl;
	cin >> belanja;
	
	if (belanja > 150000){
		cout << "Selamat berhubung belanjaan anda diatas 150.000 anda mendapatkan suvenir sebagai hadiahnya" << endl;
	} else {
		printf("maaf anda ngga dapet suvenir mwehehe...\n");
	}
	
	cout << "Terima kasih" << endl;
	return 0;
}
