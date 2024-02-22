#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

void solution(int n, vector<int> &v) {
    vector<int> count(n);
    for (int i = 0; i < n; i++)
        count[i] = i + 1;
    for (int i = n - 1; i >= 0; i--) {
        if (v[i] > i) {
            cout << "IMPOSSIBLE"
                 << "\n";
            return;
        }
        int x = count[v[i]];
        count.erase(count.begin() + v[i]);
        v[i] = x;
    }
    for (int i = 0; i < n; i++) {
        cout << v[i] << " ";
    }
    cout << "\n";
    return;
}

void test() {
    vector<int> v1{0, 0, 0, 2, 0, 1, 6, 7, 6, 9};
    solution(10, v1);
    vector<int> v2(10, 0);
    solution(10, v2);
    vector<int> v3{0, 3, 4, 5, 0, 1, 2, 3, 4, 5, 6, 7};
    solution(12, v3);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // test();

    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<int> v(n);
        for (int i = 0; i < n; i++) {
            cin >> v[i];
        }
        solution(n, v);
    }

    return 0;
}
