#include <iostream>
using namespace std;

int main(){
	int tarifMotor = 2000;
	int tarifMobil = 5000;
	int lamaParkir;
	int menu;
	bool member;
	int totalBayar = 0;
	
	cout << "silahkan memilih '1' untuk motor dan '2' untuk mobil" << endl;
	cin >> menu;
	cout << "berapa lama anda parkir di smart brawijaya?" << endl;
	cin >> lamaParkir;
	cout << "apakah anda seorang civitas akademik (1 = Ya, 0 = Tidak)" << endl;
	cin >> member;
	
	switch (menu){
		case 1:
			totalBayar = tarifMotor + (lamaParkir - 1) * 1000;
			
			if (lamaParkir > 24){
				totalBayar += 50000;
			} if (member){
				totalBayar -= 2000;
			} if (totalBayar < 0) totalBayar = 0;
			
			cout << "Berikut besaran biaya parkir anda" << endl;
			cout << totalBayar << endl;
			break;
			
		case 2:
			totalBayar = tarifMobil + (lamaParkir - 1) * 2000;
			
			if (lamaParkir > 24){
				totalBayar += 50000;
			} if (member){
				totalBayar -= 2000;
			} if (totalBayar < 0) totalBayar = 0;

			cout << "Berikut tarif parkir anda" << endl;
			cout << totalBayar << endl;
			break;
			
		default:
			cout << "who?? ALERTTTT ANOMALI DETECTED!!!!!" << endl;
	}
	return 0;
}
