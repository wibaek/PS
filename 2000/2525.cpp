#include <iostream>
using namespace std;

int main() {
    int a, b, c;
    cin >> a >> b >> c;
    a = a * 60 + b + c;
    a = a % (60 * 24);
    cout << a / 60 << " " << a % 60 << endl;

    return 0;
}
