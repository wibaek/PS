#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k, a;
    cin >> n >> k;
    vector<int> v;
    for (int i = 0; i < n; i++) {
        cin >> a;
        v.push_back(a);
    }
    sort(v.begin(), v.end());

    int ans = 0;
    for (int i = n - 1; i >= 0; i--) {
        if (k >= v[i]) {
            ans += k / v[i];
            k %= v[i];
        }
    }

    cout << ans;

    return 0;
}
