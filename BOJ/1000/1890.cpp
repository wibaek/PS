#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<vector<int>> board(n, vector<int>(n)); // board[y][x]
    vector<vector<long long int>> dp(n, vector<long long int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> board[i][j];
            dp[i][j] = 0;
        }
    }

    dp[0][0] = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if ((i == n - 1) && (j == n - 1)) {
                break;
            }
            if (i + board[i][j] < n) {
                dp[i + board[i][j]][j] += dp[i][j];
            }
            if (j + board[i][j] < n) {
                dp[i][j + board[i][j]] += dp[i][j];
            }
        }
    }
    cout << dp[n - 1][n - 1];

    return 0;
}
