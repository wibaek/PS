#include <iostream>

using namespace std;

int main() {
    int n, m, a, b, temp;
    cin >> n >> m;
    int *arr = new int[n];
    for (int i = 0; i < n; i++) {
        arr[i] = i + 1;
    }
    while (m--) {
        cin >> a >> b;
        temp = arr[a - 1];
        arr[a - 1] = arr[b - 1];
        arr[b - 1] = temp;
    }
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}
