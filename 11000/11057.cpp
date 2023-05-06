#include <iostream>
using namespace std;

int main() {
    int l[10] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
    int n;
    cin >> n;
    for (int i = 1; i < n; i++) {
        for (int j = 9; j >= 0; j--) {
            for (int k = j - 1; k >= 0; k--) {
                l[j] += l[k] % 10007;
            }
        }
    }
    int sum = 0;
    for (int i = 0; i < 10; i++)
        sum += l[i] % 10007;
    cout << sum % 10007;

    return 0;
}
