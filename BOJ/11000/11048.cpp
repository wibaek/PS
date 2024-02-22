#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int y, x, n;
    cin >> y >> x;
    vector<vector<int>> v;
    vector<vector<int>> dp;
    for (int i = 0; i < y; i++) {
        v.push_back(vector<int>());
        dp.push_back(vector<int>());
        for (int j = 0; j < x; j++) {
            cin >> n;
            v[i].push_back(n);
            dp[i].push_back(0);
        }
    }
    dp[0][0] = v[0][0];
    for (int i = 1; i < y; i++) {
        dp[i][0] = v[i][0] + dp[i - 1][0];
    }
    for (int i = 1; i < x; i++) {
        dp[0][i] = v[0][i] + dp[0][i - 1];
    }
    for (int i = 1; i < y; i++) {
        for (int j = 1; j < x; j++) {
            dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]) + v[i][j];
        }
    }

    cout << dp[y - 1][x - 1];

    return 0;
}
