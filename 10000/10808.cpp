#include <iostream>
using namespace std;

int main() {
    string qr;
    int count[26] = {0};
    cin >> qr;
    for (int i = 0; i < qr.size(); i++) {
        count[qr[i] - 'a']++;
    }
    for (int i = 0; i < 26; i++) {
        cout << count[i] << " ";
    }
    return 0;
}
