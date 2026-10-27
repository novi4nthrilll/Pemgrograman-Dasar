#include <iostream>
#include <string>
using namespace std;

class Mahasiswa {
    public:
        string nama, nim, prodi;
        int umur;
        Mahasiswa(string n, string m,string p, int u) {
            nama = n;
            nim = m;
            prodi = p;
            umur = u;
        }           
        void cetakData(){
        cout << nama << endl;
        cout << nim << endl;
        cout << prodi << endl;
        cout << umur << endl;
        }
};

int main(){// di main()
    Mahasiswa mhs1("Bela Luna", "1601","TI", 18);
    mhs1.cetakData();
    return 0;
}