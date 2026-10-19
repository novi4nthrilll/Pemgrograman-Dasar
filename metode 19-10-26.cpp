#include <iostream>
using namespace std;

int tukar(int &a, int &b){
	int t = a;
	a = b;
	b = t;
}

int main(){
	int a = 4;
    int b = 5;
    tukar(a,b);
    cout << a << " " << b << endl;
//	cout << "hasilnya: " << tukar(a,b) << a << b << endl;
	cout << "Hasilnya: " << tukar(a,b);
	return 0;
}
