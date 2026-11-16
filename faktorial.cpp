#include <iostream>
using namespace std;

int faktorial(int n) {
    if (n <= 0) {
        cout << n << endl;
        return 1;
    }
    cout << n << endl;
    return n * faktorial(n - 1);
}

int main(){
    int angka;
    cout << faktorial(5) << endl;
}
