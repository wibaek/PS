#include <iostream>
using namespace std;

int main() {
    int n;
    string str;
    char vowel[12] = {'k', 'i', 'j', 'u', 'h', 'y',
                      'n', 'b', 'm', 'l', 'o', 'p'};
    cin >> n;
    cin >> str;
    bool isVowel = false;
    for (int i = 0; i < 12; i++) {
        if (str[n - 1] == vowel[i]) {
            isVowel = true;
        }
    }
    if (isVowel)
        cout << 0;
    else
        cout << 1;

    return 0;
}
