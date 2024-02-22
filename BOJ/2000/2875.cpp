#include <algorithm>
#include <iostream>
using namespace std;

int main() {
    int n, k, c, ans;
    cin >> n >> k >> c;
    ans = 0;
    for (int i = 0; i <= c; i++) {
        ans = max(min((n - c + i) / 2, k - i), ans);
    }
    cout << ans;

    return 0;
}
