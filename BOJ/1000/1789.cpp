#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long int s, i;
    cin >> s;
    long long int n = 0;
    for (i = 1; i < 4444444444; i++) {
        n += i;
        if (n > s) {
            break;
        }
    }
    cout << i - 1;

    return 0;
}
