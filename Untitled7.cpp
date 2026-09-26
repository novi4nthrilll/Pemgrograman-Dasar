#include <iostream>
using namespace std;

int main(){
	int nilai;
	
	cout << "masukkan nilai anda" << endl;
	cin >> nilai;
	
	if (nilai >= 80){
		printf("Nilai A\n");
	} else if (nilai >= 70){
		printf("Nilai B\n");
	} else if (nilai >= 60){
		printf("Nilai C\n");
	} else {
		printf ("Nilai D\n");
	}
}
