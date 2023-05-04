#include <iostream>
// #include <queue>
// #include <string>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    double totalScore = 0;
    double totalCredit = 0;
    string s;
    double a;
    for (int i = 0; i < 20; i++) {
        cin >> s;
        cin >> a;
        cin >> s;
        if (s == "A+") {
            totalScore += 4.5 * a;
            totalCredit += a;
        } else if (s == "A0") {
            totalScore += 4.0 * a;
            totalCredit += a;
        } else if (s == "B+") {
            totalScore += 3.5 * a;
            totalCredit += a;
        } else if (s == "B0") {
            totalScore += 3.0 * a;
            totalCredit += a;
        } else if (s == "C+") {
            totalScore += 2.5 * a;
            totalCredit += a;
        } else if (s == "C0") {
            totalScore += 2.0 * a;
            totalCredit += a;
        } else if (s == "D+") {
            totalScore += 1.5 * a;
            totalCredit += a;
        } else if (s == "D0") {
            totalScore += 1.0 * a;
            totalCredit += a;
        } else if (s == "F") {
            totalCredit += a;
        }
    }
    cout << totalScore / totalCredit << endl;

    return 0;
}
