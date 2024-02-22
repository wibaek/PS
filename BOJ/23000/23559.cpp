#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, x;
    cin >> n >> x;
    int count{(x - n * 1000) / 4000};

    vector<int> p5(n);
    vector<int> p1(n);
    int answer{0};
    for (int i = 0; i < n; i++) {
        cin >> p5[i] >> p1[i];
        p5[i] -= p1[i];
        answer += p1[i];
    }
    sort(p5.begin(), p5.end());
    for (int i = n - 1; i >= 0; i--) {
        if (count <= 0)
            break;
        if (p5[i] <= 0)
            break;
        answer += p5[i];
        count--;
    }

    cout << answer;

    return 0;
}
