#include <iostream>
using namespace std;

int main() {
    int count, a, b;
    string qr;
    cin >> count;
    while (count--) {
        cin >> qr;
        a = qr[0] - '0';
        b = qr[2] - '0';
        cout << a + b << endl;
    }
    return 0;
}
