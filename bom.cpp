#include <iostream>
using namespace std;

int main() {
    int papan[9] = {0, 0, 0, 0, 1, 0, 0, 0, 0};  // bom di index 4 (posisi 5)
    int tebakan;
    bool ketemu = false;
    
    // tampilin papan
    for(int i = 0; i < 9; i++) {
        cout << "[" << i+1 << "] ";
        if((i+1) % 3 == 0) cout << endl;   // pindah baris tiap 3 kotak
    }
    
    // loop tebakan
    while(!ketemu) {
        cout << "Tebak posisi bom (1-9): ";
        cin >> tebakan;
        
        if(papan[tebakan - 1] == 1) {
            cout << "BOOM! Kena bom!" << endl;
            ketemu = true;
        } else {
            cout << "Aman, coba lagi!" << endl;
        }
    }
}