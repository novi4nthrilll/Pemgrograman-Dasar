#include <iostream>
#include <string>
using namespace std;

int main(){
    cout << "Masukkan 4 angka (2x2):" << endl;

    int data[2][2];
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 2; j++){
            cin >> data[i][j];
        }
    } cout << endl;

    int total = 0;
    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < 2; j++) {
            total = total + data[i][j];
        }
    }

    cout << "Matrix: " << endl;
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 2; j++){
            cout << data[i][j] << "\t"; 
        }
        cout << endl;
    } cout << endl;
    cout << "Total: " << total << endl;


    return 0;
}