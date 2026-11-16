#include <iostream>
using namespace std;

// 1. Sub-program faktorial
int faktorial(int n) {
    int f = 1;
    for (int i = 1; i <= n; i++) {
        f = f * i;
    }
    return f;
}

// 2. Sub-program kombinasi (manggil faktorial)
int kombinasi(int n, int k) {
    return faktorial(n) / (faktorial(k) * faktorial(n - k));
}

int main() {
    // Main cukup manggil yang udah jadi
    cout << kombinasi(5, 2) << endl;
    return 0;
}
