#include <algorithm>
#include <cmath>
#include <iostream>
using namespace std;

void solution() {
    int x1, y1, r1;
    int x2, y2, r2;

    cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;

    if (x1 == x2 && y1 == y2 && r1 == r2) {
        cout << -1 << endl;
        return;
    }

    double d = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
    int diff = r1 > r2 ? r1 - r2 : r2 - r1;
    if (d == r1 + r2 || d == abs(r1 - r2))
        cout << 1 << endl;
    else if (d < r1 + r2 && diff < d)
        cout << 2 << endl;
    else
        cout << 0 << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solution();
    }

    return 0;
}
