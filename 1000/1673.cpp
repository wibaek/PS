#include <iostream>
using namespace std;

int main() {
    int n, k;
    while (cin >> n >> k) {
        int ans{0};
        int d{0};
        while (n) {
            ans += n;
            d += n;
            n = 0;
            n += d / k;
            d = d % k;
        }
        cout << ans << endl;
    }

    return 0;
}
