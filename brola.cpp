#include <iostream>
using namespace std;

string cekKelulusan(int nilai){
    if(nilai >= 75){
        return "Lulus";
    } else if(nilai >= 50){
        return "Remedial";
    } else {
        return "Gagal";
    }
}

int main(){
    cout << "Nilai 80: " << cekKelulusan(80) << endl;
    cout << "Nilai 60: " << cekKelulusan(60) << endl;
    cout << "Nilai 40: " << cekKelulusan(40) << endl;
    return 0;
}