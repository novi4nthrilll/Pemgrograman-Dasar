#include <iostream>
#include <string>
using namespace std;

class Bola{
    public:
        int jari2;
        string warna;

        Bola(double r, string w){
            jari2 = r;
            warna = w;
        }

        double hitungVolume(){
            return(4.0 / 3.0) * 3.14 * jari2 * jari2 * jari2;
        }
        void info(){
        cout << "Warna Bola : " << warna << endl;
        cout << "Jari-jari  : " << jari2 << endl;
        cout << "Volume     : " << hitungVolume() << endl;
        cout << "--------------------" << endl;
}

};

int main(){
    Bola bola1(14.9, "merah");
    bola1.info();
    return 0;
}