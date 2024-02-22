#include <algorithm>
#include <cmath>
#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int m, d;
    cin >> m >> d;
    if (m == 2 && d == 18)
        cout << "Special";
    else if ((m == 1) || (m == 2 && d < 18))
        cout << "Before";
    else
        cout << "After";

    return 0;
}
