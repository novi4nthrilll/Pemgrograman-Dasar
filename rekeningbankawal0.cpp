#include <iostream>
#include <string>
using namespace std;

class RekeningBank {
    private:
        int saldo;

    public:
        string nomor;
        string nama;
        
        RekeningBank(string no = "tidak ada", string n = "", int s = 0){
            this -> saldo = s;
            this -> nama = n;
            this -> nomor = no;
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

class Nasabah {
    private:
        string nama;
        RekeningBank* rekening; // relasi (pointer)
    
    public:
        Nasabah(string nama, RekeningBank* r) {
            this->nama = nama;
            this->rekening = r;
        }

    void info() const {
        cout << nama << ": " << rekening->getSaldo() << endl;
    }

    RekeningBank* getRekening() {
            return rekening;
        }
};

int main() {
    RekeningBank budi("004", "budi", 300000);
    // RekeningBank r("001", 100000);
    Nasabah nbudi("Budi", &budi);
    nbudi.info();
    cout << budi.getSaldo() << endl;
    budi.setor(200000);
    budi.info();
    cout << budi.getSaldo() << endl;
    budi.tarik(100000);
    budi.info();
    return 0;
}