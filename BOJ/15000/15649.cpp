#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

bool isInVector(vector<int> &v, const int &n) {
    for (int i : v) {
        if (i == n)
            return true;
    }
    return false;
}

void rec(vector<int> &v, const int &n, const int &m) {
    if (v.size() == m) {
        for (int i : v) {
            cout << i << " ";
        }
        cout << "\n";
        return;
    }
    for (int i = 1; i <= n; i++) {
        if (isInVector(v, i)) {
            continue;
        }
        v.push_back(i);
        rec(v, n, m);
        v.pop_back();
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<int> v;
    rec(v, n, m);

    return 0;
}
