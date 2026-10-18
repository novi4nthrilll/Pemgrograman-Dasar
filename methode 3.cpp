#include <iostream>
using namespace std;

bool isGenap(int angka){
	return angka % 2 == 0;
}

int main(){
	for(int i = 1; i <= 10; i++){
		if(isGenap(i)){
			cout << i << "\t";
		}
	}
}
