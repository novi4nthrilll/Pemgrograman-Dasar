#include <iostream>
using namespace std;

int main(){
    int data[] = {45, 12, 78, 33, 90, 21, 67};
    int n = sizeof(data) / sizeof(data[0]);
    
    int max = 0;

    for(int i = 1; i < n; i++){
        if(data[i] > max){
            max = data[i];
        }
    }
    cout << "Nilai terbesar: " << max << endl;
    return 0;
}