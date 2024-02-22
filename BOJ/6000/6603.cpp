#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <vector>
using namespace std;

void rec(const vector<int> v, vector<int> mem, int n, const int k) {
    if (mem.size() == 6) {
        for (int i = 0; i < 6; i++) {
            cout << mem[i] << ' ';
        }
        cout << '\n';
        return;
    }
    if (n > v.size())
        return;
    for (int i = n; i < v.size(); i++) {
        mem.push_back(v[i]);
        rec(v, mem, i + 1, k);
        mem.pop_back();
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int k;
    while (true) {
        cin >> k;
        if (k == 0)
            break;

        vector<int> v(k);
        for (int i = 0; i < k; i++) {
            cin >> v[i];
        }
        vector<int> mem;
        rec(v, mem, 0, k);
        cout << '\n';
    }

    return 0;
}
