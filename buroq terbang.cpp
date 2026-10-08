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
	int mama;
	int olla;
	cin >> olla;
	
	for(int i = 1; i <= 10; i++){
		mama = olla * i;
		cout << olla << "x " << i << "= " << mama << endl;
	}
	return 0;
}
