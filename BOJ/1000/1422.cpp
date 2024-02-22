#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool compare(const int a, const int b) {
    string aa = to_string(a);
    string bb = to_string(b);
    if (aa + bb > bb + aa)
        return true;
    else
        return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int k, n;
    cin >> k >> n; // n >= k
    int repeat = n - k;
    int largest = 0;

    vector<int> v(k);
    for (int i = 0; i < k; i++) {
        cin >> v[i];
        if (v[i] > largest) {
            largest = v[i];
        }
    }
    sort(v.begin(), v.end(), compare);

    bool repeated = false;
    for (int i : v) {
        cout << i;
        if (i == largest && !repeated) {
            while (repeat--) {
                cout << i;
            }
            repeated = true;
        }
    }

    return 0;
}
