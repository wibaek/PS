#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, k; // 물건의 수, 버틸 수 있는 무게
    cin >> n >> k;
    vector<int> w(n + 1); // 물건의 무게
    vector<int> v(n + 1); // 물건의 가치
    vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));
    for (int i = 1; i <= n; ++i) {
        cin >> w[i] >> v[i];
    }

    // 각 물건별로 반복문을 돌며, 동적계획법으로 풀어나간다
    // 만약 물건이 들어갈 수 있는 무게가 된다면, 물건을 넣었을 때의 가치와
    // 넣지 않았을 때의 가치를 비교하여 더 큰 값을 넣는다
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= k; j++) {
            if (j < w[i]) {
                dp[i][j] = dp[i - 1][j];
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - w[i]] + v[i]);
            }
        }
    }
    cout << dp[n][k] << "\n";
    return 0;
}
