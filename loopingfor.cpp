#include <iostream>
using namespace std;

int main(){
    int total = 0;
    int i = 1;
    int angka;

    for(int i = 20; i >= 2; i-=2){
        cout << i << "\t";
    }
    
    cout << endl;

    while(total < 50){
        total = total + i;
        i++;
    }

    cout << total << endl;

    do{
        cout << "=== MENU ===" << endl;
        cout << "1. Sapa" << endl;
        cout << "2. Hitung" << endl;
        cout << "0. Keluar" << endl;
        cout << "pilih: ";
        cin >> angka;

        if(angka == 1){
            cout << "haloo" << endl;
        } else if(angka == 2){
            cout << "1 + 1 = 2" << endl;
        } else if(angka == 0){
            cout << "bye byee";
        } else{
            cout << "invalid" << endl;
        }
    } while(angka != 0);

    return 0;
}

