//Devin Andika Saputra
//2651500301111020
#include <stdio.h>
#include <iostream>
using namespace std;

int main() {
	int a;
	int b;

	cout << "masukkan bilangan yang ingin anda jumlahkan" << endl;
	cout << "masukkan bilangan pertama: " << endl;
	cin >> a;
	cout << "masukkan bilangan kedua:" << endl;
	cin >> b;

	int c;
	cout << "Pilih operasi (1: Tambah, 2: Kali, 3: Bagi, Lainnya: Kurang): " << endl;
	cin >> c;

	switch(c) {
		case 1:
			cout << "berikut hasil pertambahan dari 'a' dan 'b':" << endl;
			cout << a + b << endl;
			break;
		case 2:
			cout << "berikut hasil perkalian dari 'a' dan 'b':" << endl;
			cout << a * b << endl;
			break;
		case 3:
			cout << "berikut hasil pembagian dari 'a' dan 'b':" << endl;
			cout << a / b << endl;
			break;
		default:
			cout << "berikut hasil pengurangan dari 'a' dan 'b':" << endl;
			cout << a - b << endl;
	}
	return 0;
}

