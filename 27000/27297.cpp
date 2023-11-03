#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
#define endl "\n"
using namespace std;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;
    vector<vector<long long>> v(
        n, vector<long long>(m, 0)); // v[dimension][people]
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> v[j][i];
        }
    }

    vector<long long> ans;
    long long total{0};
    for (int i = 0; i < n; i++) {
        sort(v[i].begin(), v[i].end());
        ans.push_back(v[i][m / 2]);
        for (int j = 0; j < m; j++) {
            total += abs(v[i][j] - ans[i]);
        }
    }

    cout << total << endl;
    for (long long a : ans) {
        cout << a << " ";
    }
    return 0;
}
