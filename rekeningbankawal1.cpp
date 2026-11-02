#include <iostream>
#include <string>
using namespace std;

class RekeningBank {
        private:
            string nomor;
            int saldo;

        public:
            RekeningBank(string nomor, int saldo) {
                this->nomor = nomor;
                this->saldo = saldo;
            }

        int getSaldo() const { return saldo; }

        void setor(int jumlah) { saldo += jumlah; }
        void tarik(int jumlah) { saldo -= jumlah; }
        
        void info() {
        cout << nomor << " | " << saldo << endl;
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
    RekeningBank budi("Barlian", 300000);
    cout << budi.getSaldo() << endl;
    budi.setor(200000);
    budi.info();
    cout << budi.getSaldo() << endl;
    budi.tarik(100000);
    budi.info();
    RekeningBank r("001", 100000);
    Nasabah rosa("Rosa", &r);
    rosa.info();
    return 0;
}