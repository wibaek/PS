#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, a;
    cin >> n;
    vector<int> v;
    vector<int> dp;
    for (int i = 0; i < n; i++) {
        cin >> a;
        v.push_back(a);
        dp.push_back(0);
    }
    dp[0] = v[0];
    if (n >= 1) {
        dp[1] = v[0] + v[1];
    }
    if (n >= 2) {
        dp[2] = max(v[0] + v[2], v[1] + v[2]);
        dp[2] = max(dp[2], dp[1]);
    }
    for (int i = 3; i < n; i++) {
        dp[i] = v[i] + max(dp[i - 2], dp[i - 3] + v[i - 1]);
        dp[i] = max(dp[i], dp[i - 1]);
    }

    cout << dp[n - 1];

    return 0;
}
