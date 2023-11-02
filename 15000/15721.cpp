#include <algorithm>
#include <cmath>
#include <iostream>
using namespace std;

int a, t, c;
int p_count{0}, d_count{0};
int ans{-1};
bool check() {
    if (c == 0 && p_count == t) {
        cout << ans % a;
        return true;
    } else if (c == 1 && d_count == t) {
        cout << ans % a;
        return true;
    }

    return false;
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> a >> t >> c; // 사람, 구하고자 하는 번째
    // c가 0:뻔, 1:데기

    int round{2};

    while (true) {
        p_count++;
        ans++;
        if (check())
            return 0;
        d_count++;
        ans++;
        if (check())
            return 0;
        p_count++;
        ans++;
        if (check())
            return 0;
        d_count++;
        ans++;
        if (check())
            return 0;

        for (int i = 0; i < round; i++) {
            p_count++;
            ans++;
            if (check())
                return 0;
        }
        for (int i = 0; i < round; i++) {
            d_count++;
            ans++;
            if (check())
                return 0;
        }
        round++;
    }
    return 0;
}
