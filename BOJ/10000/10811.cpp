#include <iostream>
using namespace std;

int main() {
    int n, m, a, b;
    cin >> n >> m;
    int *arr = new int[n];
    for (int i = 0; i < n; i++) {
        arr[i] = i + 1;
    }
    while (m--) {
        cin >> a >> b;
        a -= 1;
        b -= 1;
        int *tempArr = new int[b - a + 1];
        for (int i = 0; i <= b - a; i++) {
            tempArr[i] = arr[a + i];
        }
        for (int i = 0; i <= b - a; i++) {
            arr[a + i] = tempArr[b - a - i];
        }
        delete[] tempArr;
    }
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}
