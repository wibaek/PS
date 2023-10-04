#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

double triangle(double x1, int y1, double x2, int y2, double x3, int y3) {
    return (x1 * y2 + x2 * y3 + x3 * y1 - x2 * y1 - x3 * y2 - x1 * y3) / 2;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    vector<pair<int, int>> coord(n);
    for (int i = 0; i < n; i++) {
        cin >> coord[i].first >> coord[i].second;
    }

    long double answer = 0;
    for (int i = 1; i < n - 1; i++) {
        answer +=
            triangle(coord[0].first, coord[0].second, coord[i].first,
                     coord[i].second, coord[i + 1].first, coord[i + 1].second);
    }

    cout.precision(1);
    cout << fixed << abs(answer);
    return 0;
}
