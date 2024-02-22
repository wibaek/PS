#include <iostream>
using namespace std;

int main() {
    int x, y;
    cin >> x >> y;
    int days[12] = {0, 3, 3, 6, 1, 4, 6, 2, 5, 0, 3, 5};
    y += days[x - 1];
    string day[7] = {"SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT"};
    cout << day[y % 7];

    return 0;
}
