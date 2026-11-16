#include<iostream>
using namespace std;

class Mobil{
    public:
        string nopol;
        string warna;
        string manufaktur;
        double kecepatan,waktu,sekon,jarak;
        Mobil();
        Mobil(string x, string y, string z, double v);
        void displayMessege();
        void chat();
        void setWaktu(double waktu);
        void ubahSekon(double sekon);
        void setKecepatan(double kecepatan);
        void hitungJarak();

    private:
        void ubahKecepatan(double kecepatan);
    };
    
Mobil::Mobil(){
    nopol = "";
    warna = "";
    manufaktur = "";
    kecepatan = 0.0;
    waktu = 0.0;
    sekon = waktu * 3600;
    jarak = 0.0;
}

Mobil::Mobil(string x, string y, string z, double v){
    nopol = x;
    warna = y;
    manufaktur = z;
    kecepatan = v;
    waktu = 0.0;
    sekon = 0.0;
    jarak = 0.0;
}

void Mobil::chat(){
    cout << "Masukkan Nomor polisi: ";
    cin >> nopol;
    cout << "Masukkan Warna Mobil: ";
    cin >> warna;
    cout << "Masukkan Manufaktur Mobil: ";
    cin >> manufaktur;

    double inputKecepatan;
    cout << "Masukkan Kecepatan (km/h): "; cin >> inputKecepatan;
    setKecepatan(inputKecepatan);

    double inputWaktu;
    cout << "Masukkan Waktu (jam)    : "; cin >> inputWaktu;
    setWaktu(inputWaktu);

    hitungJarak();
}

void Mobil::displayMessege(){
cout << "----------------------------------------" << endl;
cout << "Nopol\t\t: " << nopol << endl;
cout << "Warna\t\t: " << warna << endl;
cout << "Manufaktur\t: " << manufaktur << endl;
cout << "Kecepatan\t: " << kecepatan << " m/s" << endl;
cout << "Waktu\t\t: " << waktu << " jam" << endl; 
cout << "Sekon\t\t: " << sekon << " detik" << endl;
cout << "Jarak\t\t: " << jarak / 1000 << " km" << endl;
cout << "----------------------------------------" << endl;
}

void Mobil::setWaktu(double waktu){
    this->waktu = waktu;
    ubahSekon(waktu);
}

void Mobil::ubahSekon(double sekon){
    sekon = sekon * 3600;
    this->sekon = sekon;
}

void Mobil::setKecepatan(double kecepatan){
    this->kecepatan = kecepatan;
    ubahKecepatan(kecepatan);
}

void Mobil::ubahKecepatan(double kecepatan){
    kecepatan = kecepatan / 3.6;
    this->kecepatan = kecepatan;
}

void Mobil::hitungJarak(){
    jarak = kecepatan * sekon;
}

int main(){
    Mobil mobil_a;
    // mobil_a.nopol = "N 7221 WZ";
    // mobil_a.warna = "Biru";
    // mobil_a.manufaktur = "Mitsubishi";
    // mobil_a.kecepatan = 50.0;
    // Mobil mobil_b("N 2010 KT", "Merah", "Toyota", 100.0);
    // mobil_a.displayMessege();
    // mobil_b.displayMessege();
    Mobil mobil_b;
    mobil_a.chat();
    mobil_a.displayMessege();
    return 0;
}