#include <iostream>
#include <string>
using namespace std;

class Handphone{
    public:
        string merek;
        int baterai;

    Handphone(string merek = "", int baterai = 0){
        this -> merek = merek;
        this -> baterai = baterai;
    }

    void charge(){
        if(baterai < 100){
            baterai = 100;
            
            cout << "HP-luuu udh full woyyy" << endl;
        } else{
            cout << "HP-luuuu emg full dari awal kucay lahh" << endl;
        }
    }

    void mainGame(){
        baterai -= 20;
        cout << "Lu maen nih jadinya baterai lu segini: " << baterai << endl;
    }

    void info(){
        cout << merek << " baterainya " << baterai << "%";
    }
};


int main(){
    Handphone hp("smasung", 40);
    hp.charge();
    hp.mainGame();
    hp.info();
    return 0;
}