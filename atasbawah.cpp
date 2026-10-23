#include <iostream>
using namespace std;

int main(){
    for(int i = 1; i <= 5; i++){
        for(int j=1; j <= 5; j++){
            int total = i * j;
            cout << i << "x" << j << "=" << total << "\t";
        }
        cout << endl;
    }
    return 0;
}
