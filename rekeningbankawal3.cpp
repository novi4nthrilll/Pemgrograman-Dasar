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

        RekeningBank(string nomor)
            : RekeningBank(nomor, 0){}
        
        int getSaldo() const { return saldo; }
        
        void setor(int jumlah) { saldo += jumlah; }
        void tarik(int jumlah) { saldo -= jumlah; }
        
        void info() const {
        cout << nomor << " | " << saldo << endl;
        }

        void setNomor(const string& nomorbaru){
            this->nomor = nomorbaru;
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

    RekeningBank* getRekening() const {
            return rekening;
        }

    void setNama(const string& namabaru){if (!namabaru.empty()) this->nama = namabaru;}
    void setRekening(RekeningBank* rekeningbaru) {if (rekeningbaru != 0){this->rekening = rekeningbaru;}}
};

int main() {
    RekeningBank budi("Barlian", 300000);
    cout << "Saldo Awal Barlian: " << budi.getSaldo() << endl;
    
    budi.setor(200000);
    budi.info();
    
    cout << "Saldo setelah setor: " << budi.getSaldo() << endl;
    
    budi.tarik(100000);
    budi.info();

    RekeningBank r("001", 100000);
    Nasabah rosa("Rosa", &r);
    rosa.info();
    return 0;
}