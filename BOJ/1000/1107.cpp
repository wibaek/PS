#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool includeNumber(int object, int n) {
    string s = to_string(object);
    char c = n + '0';
    for (char digit : s) {
        if (c == digit) {
            return true;
        }
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    int broken_count;
    cin >> broken_count;

    vector<int> v(broken_count);
    for (int i = 0; i < broken_count; i++) {
        cin >> v[i];
    }

    if (broken_count == 10) {
        int answer = (n < 100) ? 100 - n : n - 100;
        cout << answer;
        return 0;
    }

    int low_answer{n + 1}, high_answer{n - 1};

    bool flag = true;
    while (flag && low_answer >= 1) {
        low_answer--;
        flag = false;
        for (int i : v) {
            if (includeNumber(low_answer, i))
                flag = true;
        }
    }
    if (low_answer == 0 && (find(v.begin(), v.end(), 0) != v.end())) {
        low_answer = -99999999;
    }

    if (broken_count == 9 && (find(v.begin(), v.end(), 0) == v.end())) {
        int answer = (n < 100) ? 100 - n : n - 100;
        answer = min(
            static_cast<int>(n - low_answer + to_string(low_answer).length()),
            answer);
        cout << answer;
        return 0;
    }

    flag = true;
    while (flag) {
        high_answer++;
        flag = false;
        for (int i : v) {
            if (includeNumber(high_answer, i))
                flag = true;
        }
    }
    int answer = (n < 100) ? 100 - n : n - 100;
    int answer2 = min((n - low_answer) + to_string(low_answer).length(),
                      (high_answer - n) + to_string(high_answer).length());
    answer = min(answer, answer2);

    cout << answer << endl;
    return 0;
}
