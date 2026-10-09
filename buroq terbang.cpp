#include <iostream>
using namespace std;

int main(){
//	int olla;
//	int jumlah = 0;
//	cin >> olla;
//	
//	
//	for(int i = 1; i <= olla; i++){
//		jumlah = jumlah + i;
//	}
//	cout << jumlah ;
//	int mama;
//	int olla;
//	cin >> olla;
//	
//	for(int i = 1; i <= 10; i++){
//		mama = olla * i;
//		cout << olla << "x " << i << "= " << mama << endl;
//	}

	int olla;
	cout << "Masukkan Nilai = ";
	cin >> olla;
	
	for(int i = 1; i <= olla; i++){
    	for(int j = 1; j <= i; j++){
    		cout << "* ";
    }
    cout << endl;
	}
	
	for(int i = 1; i <= olla; i++){
		for(int j = 1; j <= i; j++){
		cout << " *";
		}
		cout << endl;
	}
	
	return 0;
}
