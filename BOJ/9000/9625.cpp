#include <iostream>
// #include <queue>
// #include <string>
using namespace std;

int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(NULL);
    int k;
    cin >> k;
    int a{1}, b{0};
    for (int i = 0; i < k; ++i) {
        int temp = a;
        a = b;
        b = temp + b;
    }
    cout << a << " " << b;
    return 0;
}
