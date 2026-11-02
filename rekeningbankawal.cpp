#include <iostream>
#include <string>
using namespace std;

class RekeningBank {
    private:
        int saldo;

    public:
        string nomor;
        string nama;
        
        RekeningBank(string n = "", int s = 0){
            saldo = s;
            nama = n;
        }

        RekeningBank(string no = "tidak ada", string n = "", int s = 0){
            nomor = no;
            saldo = s;
            nama = n;
        }

        void setor(int jumlah) { saldo += jumlah; }
        void tarik(int jumlah) { saldo -= jumlah; }
        
        void info() {
        cout << nomor << " | " << nama << " | " << saldo << endl;
        }
        
        int getSaldo(){
            return saldo;
        }
};

int main() {
    RekeningBank budi("004", "budi", 300000);
    budi.info();
    cout << budi.getSaldo() << endl;
    budi.setor(200000);
    budi.info();
    cout << budi.getSaldo() << endl;
    budi.tarik(100000);
    budi.info();
    return 0;
}