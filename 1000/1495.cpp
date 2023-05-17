#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, s, m;
    cin >> n >> s >> m;
    vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, false));
    dp[0][s] = true;

    for (int i = 0; i < n; i++) {
        cin >> s;
        for (int j = 0; j <= m; j++) {
            if (dp[i][j]) {
                if (j - s >= 0)
                    dp[i + 1][j - s] = true;
                if (j + s <= m)
                    dp[i + 1][j + s] = true;
            }
        }
    }
    for (int i = m; i >= 0; i--) {
        if (dp[n][i]) {
            cout << i;
            return 0;
        }
    }
    cout << -1;
    return 0;
}
