#include <iostream>
#include <string>
using namespace std;

int main () {
	int x = 5;
	long long nim = 265150301111020;
	long long inputnim;
	string nama;
	string nama1 = "Devin";
	
	x == 5 ? cout << "Benar\n" : cout << "Salah\n";
	cout << "Masukkan Nama Lengkap beserta NIM Anda:" << endl;
	cout << "Nama: ";
	cin >> nama;
	
	cout << "NIM: ";
	cin >> inputnim;
	
	cout << "=======================" << endl;
	cout << "    Informasi Data" << endl;
	cout << "=======================" << endl;
	nama == nama1 ? cout << nama << endl : cout << "input nama salah" << endl;
	inputnim == nim ? cout << nim << endl : cout << "input nim salah"<< endl;
	cout << "=======================" << endl;
	return 0;
}
