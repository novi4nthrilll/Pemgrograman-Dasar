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

        int cekSaldo(){ 
            return saldo; 
        }
};

int main(){
    Rekening rkn1("555555", "Nanda Gay", 40000);
    rkn1.setor(40);
    cout << "Saldo telah disetorkan" << rkn1.cekSaldo() << endl;

    rkn1.tarik(20);
    cout << "Saldo setelah tarik: " << rkn1.cekSaldo() << endl;

    rkn1.cekSaldo();
    cout << "info saldo: " << rkn1.cekSaldo() << endl;
    return 0;

}
