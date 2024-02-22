#include <algorithm>
#include <cmath>
#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int z;
    cin >> z;
    while (z--) {
        int a, b;
        cin >> a >> b;
        if (a % 2 == 1 && b % 2 == 1)
            cout << (a * b - 1) / 2 << endl;
        else
            cout << a * b / 2 << endl;
    }

    return 0;
}
