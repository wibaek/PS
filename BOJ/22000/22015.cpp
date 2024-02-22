#include <algorithm>
#include <cmath>
#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int a, b, c;
    cin >> a >> b >> c;
    cout << 3 * max(a, max(b, c)) - a - b - c;

    return 0;
}
