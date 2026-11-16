#include <iostream>
using namespace std;

int main(){
    int tinggi = 10;
    
    for(int i = 1; i <= tinggi; i++){
        
        // cetak spasi: makin ke bawah makin sedikit
        for(int s = 0; s < tinggi - i; s++){
            cout << " ";
        }
        
        // cetak bintang: ganjil, makin ke bawah makin banyak
        for(int b = 0; b < 2*i - 1; b++){
            cout << "*";
        }
        
        cout << endl;
    }
    
    return 0;
}