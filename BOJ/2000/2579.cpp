#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> v, ans;
    int n, a;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a;
        v.push_back(a);
        ans.push_back(0);
    }

    ans[0] = v[0];
    ans[1] = v[0] + v[1];
    ans[2] = max(v[0] + v[2], v[1] + v[2]);

    for (int i = 3; i < n; i++) {
        ans[i] = v[i] + max(ans[i - 2], v[i - 1] + ans[i - 3]);
    }
    cout << ans[n - 1];

    return 0;
}
