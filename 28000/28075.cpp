#include <iostream>
#include <vector>
using namespace std;

int m;
vector<int> v(6);

int rec(int leftDay, int prevTask, int totalScore) {
    if (leftDay == 0) {
        if (totalScore >= m)
            return 1;
        return 0;
    }
    int a = 0;
    for (int i = 0; i < 6; i++) {
        if (prevTask == -1)
            a += rec(leftDay - 1, i, totalScore + v[i]);
        else if (i % 3 == prevTask % 3)
            a += rec(leftDay - 1, i, totalScore + v[i] / 2);
        else
            a += rec(leftDay - 1, i, totalScore + v[i]);
    }
    return a;
}

int main() {
    int n;

    cin >> n >> m;
    for (int i = 0; i < 6; i++) {
        cin >> v[i];
    }
    cout << rec(n, -1, 0);

    return 0;
}
