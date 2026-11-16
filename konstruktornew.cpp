#include <iostream>
#include <string>
using namespace std;

class Mahasiswa {
    public:
        string nama, nim, prodi;
        int umur;
        Mahasiswa(string n = "", string m = "",string p = "", int u = 0) {
            this -> nama = n;
            this -> nim = m;
            this -> prodi = p;
            this -> umur = u;
        }
        void cetakData(){
        cout << "Nama :"<< nama << endl;
        cout << "NIM: " <<  nim << endl;
        cout << "Prodi: " << prodi << endl;
        cout << "Umur: " << umur << endl;
        cout << "-----------------------" << endl;
        }
};

int main(){ // di main()
    Mahasiswa mhs1("Bela Luna", "1601","TI", 18);
    Mahasiswa mhs2("olla lala", "2651");
    Mahasiswa mhs3("syakira", "2543", "TK");
    mhs1.cetakData();
    mhs2.cetakData();
    mhs3.cetakData();
    return 0;
}