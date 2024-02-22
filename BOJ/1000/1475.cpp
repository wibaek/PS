#include <iostream>
using namespace std;

int main() {
    int arr[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    int n;
    cin >> n;
    while (n >= 10) {
        arr[n % 10]++;
        n /= 10;
    }
    arr[n]++;
    arr[6] += arr[9];
    arr[9] = 0;
    arr[6] = (arr[6] + 1) / 2;
    int max = 0;
    for (int i = 0; i < 10; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    cout << max;

    return 0;
}
