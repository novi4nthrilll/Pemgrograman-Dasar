#include <iostream>
using namespace std;

int main() {
    int data[3];   
    
    
    cout << "Masukkan 3 angka:" << endl;
    for(int i = 0; i < 3; i++) {
        cin >> data[i];
    }
    
    
    cout << "Yang lu masukin: ";
    for(int i = 0; i < 3; i++) {
        cout << data[i] << " ";
    }
    cout << endl;
    
    return 0;
}