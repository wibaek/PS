#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    int s_ptr{0};
    int l_ptr{n - 1};

    int answers{v[0]};
    int answerl{v[n - 1]};

    while ((l_ptr - s_ptr > 1) && (answerl + answers != 0)) {
        if (v[l_ptr] + v[s_ptr] < 0) {
            s_ptr++;
        } else if (v[l_ptr] + v[s_ptr] > 0) {
            l_ptr--;
        }
        if (abs(answerl + answers) >= abs(v[s_ptr] + v[l_ptr])) {
            answerl = v[l_ptr];
            answers = v[s_ptr];
        }
    }
    cout << answers << " " << answerl;

    return 0;
}
