#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
#define INF 1
using namespace std;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    // INPUT
    int n, k;
    cin >> n >> k;

    // walk, bicycle
    vector<vector<int>> money(2, vector<int>(n));
    vector<vector<int>> time(2, vector<int>(n));
    vector<vector<int>> dp(n, vector<int>(k + 1, -INF));

    for (int i = 0; i < n; i++) {
        cin >> time[0][i] >> money[0][i] >> time[1][i] >> money[1][i];
    }

    if (time[0][0] <= k)
        dp[0][time[0][0]] = money[0][0];
    if (time[1][0] <= k)
        dp[0][time[1][0]] = max(money[1][0], dp[0][time[1][0]]);

    for (int i = 1; i < n; i++) {
        for (int j = 0; j <= k; j++) {
            if (dp[i - 1][j] != -INF) {
                if (j + time[0][i] <= k) {
                    dp[i][j + time[0][i]] =
                        max(dp[i - 1][j] + money[0][i], dp[i][j + time[0][i]]);
                }
                if (j + time[1][i] <= k) {
                    dp[i][j + time[1][i]] =
                        max(dp[i - 1][j] + money[1][i], dp[i][j + time[1][i]]);
                }
            }
        }
    }
    int answer{0};
    for (int i = 0; i <= k; i++) {
        if (dp[n - 1][i] != -INF)
            answer = max(answer, dp[n - 1][i]);
    }
    cout << answer;
    return 0;
}
