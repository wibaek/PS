#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool countStrikeBall(string guess, string answer, int strike, int ball) {
    // guess와 answer의 strike, ball 개수가 일치하는지 확인
    int strikeCount = 0;
    int ballCount = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (guess[i] == answer[j]) {
                if (i == j) {
                    strikeCount++;
                } else {
                    ballCount++;
                }
            }
        }
    }
    return strikeCount == strike && ballCount == ball;
}

int main() {
    int count, s, b;
    string guess;
    cin >> count;

    // 123 ~ 987 까지 가능한 모든 경우 (1~9 숫자중 중복없음)
    vector<string> whitelist;
    for (int i = 1; i < 10; i++) {
        for (int j = 1; j < 10; j++) {
            for (int k = 1; k < 10; k++) {
                if (i != j && i != k && j != k) {
                    whitelist.push_back(to_string(i * 100 + j * 10 + k));
                }
            }
        }
    }
    while (count--) {
        cin >> guess >> s >> b;
        for (int i = 0; i < whitelist.size(); i++) {
            if (!countStrikeBall(guess, whitelist[i], s, b)) {
                whitelist.erase(whitelist.begin() + i);
                i--;
            }
        }
    }
    cout << whitelist.size() << endl;

    return 0;
}
