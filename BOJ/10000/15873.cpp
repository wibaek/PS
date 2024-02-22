#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int x;
    cin >> x;
    if (x == 1010)
        cout << 20;
    else if (x / 10 == 10)
        cout << 10 + x % 10;
    else if (x % 10 == 0)
        cout << x / 100 + 10;
    else
        cout << x / 10 + x % 10;

    return 0;
}
