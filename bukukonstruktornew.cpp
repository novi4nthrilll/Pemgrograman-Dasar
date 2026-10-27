#include <iostream>
#include <string>
using namespace std;

class Buku{
    public:
        string judul, penulis;
        int tahun, stok;

        Buku(string j, string p, int t, int s){
            judul = j;
            penulis = p;
            tahun = t;
            stok = s;
        }

        void pinjam(){
            if(stok > 0){
                stok--;
                cout << "YATTTTAAAA ini bukumu: " << judul << endl;
                cout << "-----------------------" << endl;
             } else{
                cout << "Sorry Bukunya abissss" << endl;
                cout << "-----------------------" << endl;
            }
        }

        void kembalikan(){
            stok++;
            cout << "stok sekarang jadi: " << stok << endl;
            cout << "-----------------------" << endl;
        }
        
        void info(){
            cout << "Judul: " << judul << endl;
            cout << "Penulis: " << penulis << endl;
            cout << "Tahun: " << tahun << endl;
            cout << "Stok: " << stok << endl;
            cout << "-----------------------" << endl;
        }

        void sisa(){
            cout << "Stok: " << stok << endl;
        }
};

int main(){
    Buku buku1("Kapan dunia akan hancur", "olla", 2004, 2);
    buku1.info();
    buku1.pinjam();
    buku1.sisa();
    // buku1.kembalikan();
    return 0;
}