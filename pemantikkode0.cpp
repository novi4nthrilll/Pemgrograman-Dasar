#include <iostream>
#include <string>
using namespace std;

class Rekeningbank{
    private: int saldo;

    public:
        string nama;

        Rekeningbank(string n, int s){
            nama = n;
            saldo = s;
        }

        int getSaldo(){
            return saldo;
        }
};

int main() {
    Rekeningbank sari("Sari", 500000);
    cout << sari.nama << endl; 
    cout << sari.getSaldo() << endl;
    return 0;
}