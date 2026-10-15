#include <iostream>
using namespace std;

int main(){
        int olla[3][3] = {{1,2,3},{4,5,6},{7,8,9}};
        int lola[3][3] = {{9,8,7},{6,5,4},{3,2,1}};

        int baris = 3;
        int kolom = 3;

        cout << "ini penjumlahan antar matrix:" << endl;
        for(int i = 0; i < baris; i++){
                for(int j = 0; j < kolom; j++){
                cout << (olla[i][j] + lola[i][j]) << "\t";
                }
        cout << endl;
        }

        cout << endl;

        cout << "ini pengurangan antar matrix:" << endl;
        for(int i = 0; i < baris; i++){
                for(int j = 0; j < kolom; j++){
                cout << (olla[i][j] - lola[i][j]) << "\t";
                }
        cout << endl;
        }
return 0;
}
