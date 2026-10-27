#include <iostream>
#include <string>
using namespace std;

class Buku{
    public:
        string tgl_pinjam, tgl_kembali;

            Buku(string a = " ", string b = " "){
                this -> tgl_pinjam = a;
                this -> tgl_kembali = b;
            }

            string pinjam(){
                return tgl_pinjam;
            }

            string kembalikan(){
                return tgl_kembali;
            }

            void info(){
                cout << "Pinjam Mulai dari tanggal: " << tgl_pinjam << endl;
                cout << "Dikembalikan harus sebelum: " << tgl_kembali << endl; 
            }
};

int main(){
    Buku buku1("19 November 2045", "20 November 2045");
    buku1.info();
    return 0;
}