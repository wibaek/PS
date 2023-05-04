#include <iostream>
#include <vector>
using namespace std;

int check(bool add, int k, double d, vector<double> &v, const int &n) {
    if (add)
        d += (1 / v[k]);

    if (k == n - 1) {
        if (d <= 1.01 && d >= 0.99)
            return 1;
        else
            return 0;
    } else {
        return check(false, k + 1, d, v, n) + check(true, k + 1, d, v, n);
    }
}

int main() {
    int n, a;
    vector<double> v;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a;
        v.push_back(a);
    }
    cout << check(false, 0, 0, v, n) + check(true, 0, 0, v, n);

    return 0;
}
