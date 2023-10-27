#include <algorithm>
#include <cmath>
#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int x;
    cin >> x;
    int n;
    cin >> n;
    int total{0};
    while (n--) {
        int a, b;
        cin >> a >> b;
        total += a * b;
    }
    if (total == x)
        cout << "Yes";
    else
        cout << "No";

    return 0;
}
