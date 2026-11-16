#include <iostream>
using namespace std;

int main(){
        int olla[] = {1,2,3,4,5};
        int lola[] = {6,7};

        int n1 = sizeof(olla) / sizeof(olla[0]);
        int n2 = sizeof(lola) / sizeof(lola[0]);
	int total = 7;

	int hasil[7];

	for(int i = 0; i < n1; i++){
	hasil[i] = olla[i];
	}

	for(int i = 0; i < n2; i++){
	hasil[n1+i] = lola[i];
	}

	for(int i = 0; i < total; i++){
	cout << hasil[i] << " ";
	}
return 0;
}
