#include <iostream>
using namespace std;

int digitSum(int n) {
    int ret = 0;
    while (n > 0) {
        ret += n % 10;
        n /= 10;
    }
    return ret;
}

int main() {
    int i;
    cin >> i;
    for(int j = 0; j <= 1000000; j++){
        if (digitSum(j) + j == i) {
            cout << j;
            return 0;
        }
    }
    cout << 0;
    return 0;
}