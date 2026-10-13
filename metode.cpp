#include <iostream>
using namespace std;

int hitungluas(int p, int l){
	int L=p*l;
	return L;
}

int main(){
	
	int Luas1 = hitungluas(10,5);
	int Luas2 = hitungluas(40,3);
	int Luas3 = hitungluas(100,2);

	printf("Luas = %d\n", Luas1);
	printf("Luas = %d\n", Luas2);
	printf("Luas = %d\n", Luas3);
}

