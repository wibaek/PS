#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    vector<int> time(n);
    vector<int> price(n);
    vector<int> dp(n + 1);

    for (int i = 0; i < n; i++) {
        cin >> time[i] >> price[i];
    }

    for (int i = 0; i <= n; i++) {
        if (i >= 1) {
            dp[i] = max(dp[i], dp[i - 1]);
        }
        if (i + time[i] <= n) {
            dp[i + time[i]] = max(dp[i + time[i]], dp[i] + price[i]);
        }
    }
    cout << dp[n];
    return 0;
}
