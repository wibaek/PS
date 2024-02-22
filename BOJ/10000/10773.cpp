#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, a;
    cin >> n;
    vector<int> v(100000);
    int index = 0;
    while (n--) {
        cin >> a;
        if (a == 0 && index > 0) {
            index--;
        } else {
            v[index++] = a;
        }
    }

    long long answer = 0;
    while (index--) {
        answer += v[index];
    }

    cout << answer;

    return 0;
}
