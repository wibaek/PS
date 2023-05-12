#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, x;
    cin >> n;
    vector<int> v;
    vector<int> dp;
    for (int i = 0; i < n; i++) {
        cin >> x;
        v.push_back(x);
        dp.push_back(0);
    }
    dp[0] = v[0];
    int maxVal = dp[0];
    for (int i = 1; i < n; i++) {
        dp[i] = max(v[i], v[i] + dp[i - 1]);
        maxVal = max(maxVal, dp[i]);
    }
    cout << maxVal;
    return 0;
}
