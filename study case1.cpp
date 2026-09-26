#include <iostream>
using namespace std;

int main(){
	double berat;
	double tinggi;
	
	cout << "Menghitung BMI, untuk yang pertama masukkan berat:" << endl;
	cin >> berat;
	cout << "Lalu masukkan tinggi:" << endl;
	cin >> tinggi;
	
	double BMI = berat / (tinggi * tinggi);
	cout << "ini dia hasilnyaaa" << endl;
	cout << BMI << endl;
	return 0;
}
