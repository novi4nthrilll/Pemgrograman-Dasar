#include <iostream>
using namespace std;

int faktorial(int n) {
     return faktorial(n - 1);
}

int main() {
    cout << "Nilai dari 5! = " << faktorial(5) << endl; // output : 120
    return 0;
}