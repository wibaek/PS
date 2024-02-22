#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;
    vector<vector<int>> v(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> v[i][j];
            if (j > 0) {
                v[i][j] += v[i][j - 1];
            }
            if (i > 0) {
                v[i][j] += v[i - 1][j];
            }
            if (i > 0 && j > 0) {
                v[i][j] -= v[i - 1][j - 1];
            }
        }
    }

    int k;
    cin >> k;
    while (k--) {
        int i, j, x, y;
        cin >> i >> j >> x >> y;
        i--;
        j--;
        x--;
        y--;
        int ans = v[x][y];
        if (i > 0)
            ans -= v[i - 1][y];
        if (j > 0)
            ans -= v[x][j - 1];
        if (i > 0 && j > 0)
            ans += v[i - 1][j - 1];
        cout << ans << "\n";
    }

    return 0;
}
