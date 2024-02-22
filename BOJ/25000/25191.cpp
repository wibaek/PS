#include <algorithm>
#include <cmath>
#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int c, k, b;
    cin >> c >> k >> b;
    int v{k / 2 + b};
    cout << min(c, v);

    return 0;
}
