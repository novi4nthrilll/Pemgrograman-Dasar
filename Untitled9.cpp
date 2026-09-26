#include <iostream>
using namespace std;

int main(){
	int menu;
	
	printf("masukkan menu pilihan anda\n");
	cin >> menu;
	
	switch (menu){
		case 1:
			printf("File baru\n");
			break;
		case 2:
			printf("Buka File\n");
			break;
			
		default:
			printf("Menu Invalid");
	}
	return 0;
}
