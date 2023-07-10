#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int number;
    cin >> number;
    long long int n = 0;
    if (number > 99999999) {
        n += 90000000 * 8;
    }
    if (number > 9999999) {
        n += 9000000 * 7;
    }
    if (number > 999999) {
        n += 900000 * 6;
    }
    if (number > 99999) {
        n += 90000 * 5;
    }
    if (number > 9999) {
        n += 9000 * 4;
    }
    if (number > 999) {
        n += 900 * 3;
    }
    if (number > 99) {
        n += 90 * 2;
    }
    if (number > 9) {
        n += 9;
    }
    if (number > 9) {
        n += (number + 1 - pow(10, (to_string(number).length() - 1))) *
             to_string(number).length();
    } else {
        n = number;
    }

    cout << n << endl;

    return 0;
}
