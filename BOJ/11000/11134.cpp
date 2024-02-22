#include <iostream>
using namespace std;

int main() {
    int count, n, c;
    cin >> count;

    while (count--) {
        cin >> n >> c;
        if (n % c == 0) {
            cout << n / c << "\n";
        } else {
            cout << n / c + 1 << "\n";
        }
    }

    return 0;
}
