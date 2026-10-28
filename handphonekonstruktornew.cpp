#include <iostream>
#include <string>
using namespace std;

class Rekening {
    private:
        string nomor, pemilik;
        int saldo;
    
    public:
        Rekening(string nomor = "", string pemilik = "",int saldoAwal = 0) {
            this->nomor = nomor;
            this->pemilik = pemilik;
            this->saldo = saldoAwal;
        }

        void setor(int jumlah) {
            if (jumlah > 0){
                saldo += jumlah;
            }
        }

        bool tarik(int jumlah) {
            if (jumlah > 0 && jumlah <= saldo) {
                saldo -= jumlah;
                return true;
            }
        
            return false;
        }

        void cekSaldo(){
            cout << "Pemilik: " << pemilik << endl;
            cout << "Nomor: " << nomor << endl;
            cout << "Sisa saldo: " << saldo << endl;
        }
};

int main(){
    Rekening rkn1("555555", "Nanda Gay", 40000);
    rkn1.setor(40);
    rkn1.tarik(20);
    rkn1.cekSaldo();
    return 0;

}
