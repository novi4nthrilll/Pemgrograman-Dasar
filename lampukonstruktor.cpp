#include <iostream>
#include <string>
using namespace std;

class Lampu{
    public:
        bool menyala;
        int kecerahan;

        Lampu(bool m, int k){
            menyala = m;
            kecerahan = k;
        }

        void nyalakan(){
            if(menyala == false && kecerahan < 100){
                menyala = true;          
                kecerahan = 100;         
                cout << "Lampunyaa nyalaaa terang benderang broo (100%)" << endl;
            } else {
                cout << "Lampunya udah nyala broo, terang benderang nih!" << endl;
            }
        }

        void matikan(){
            if(menyala == false && kecerahan == 0){
                menyala = false;         
                kecerahan = 0;           
                cout << "Lampunyaaa matuyyy coyyy (0%)" << endl;
            } else {
                cout << "Lampunya udah mati dari tadi broo" << endl;
            }
        }

        void redupkan(){
            if(menyala == true && kecerahan > 0){
                kecerahan = kecerahan - 20;
                if(kecerahan <= 0){
                    kecerahan = 0;
                    menyala = false;
                    cout << "Kecerahan habis, lampunya mati bro!" << endl;
                } else {
                    cout << "Mulai redupp nihhh hehe. Sisa: " << kecerahan << "%" << endl;
                }
            } else {
                cout << "Ga bisa diredupin brooo kan mati lampunya" << endl;
            }
        }
};

int main(){
    Lampu lmp(1, -80);
    // lmp.nyalakan();
    // lmp.matikan();
    lmp.redupkan();
    return 0;
}