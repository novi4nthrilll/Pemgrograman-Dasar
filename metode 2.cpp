#include <stdio.h>
using namespace std;

int kali(int a, int b){
	int K = a*b;
	return K;
}

int main(){
	
	int hasil=kali(4, 6);
	printf("Hasil = %d", hasil);
}
