#include <iostream>
using namespace std;

int main(){
    int total = 0;
    int angka = 7;
    int tebakan = 0;
    for(int i = 10; i >= 1; i--){
        cout << i << "\t";
        total = total + i;
    } cout << total;

    cout << endl;
    while(tebakan != angka){
        cout << "Tebak angka (1-10): ";
        cin >> tebakan;
        
        if(tebakan == angka) {
            cout << "Bener! Angka rahasianya " << angka << "." << endl;
        } else {
            cout << "Salah! Coba lagi." << endl;
        }
    }
    return 0;
}
