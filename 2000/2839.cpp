#include <iostream>
#include <vector>
using namespace std;

vector<int> mem(5001, -1);

int rec(int n, int val) {
    if (n > 5000) return 0;
    if (mem[n] != -1) return 0;
    mem[n] = val + 1;
    rec(n+5, val+1);
    rec(n+3, val+1);
    return 0;
}

int main() {
    rec(5, 0);
    rec(3, 0);
    int sugar;
    cin >> sugar;
    cout << mem[sugar];
    return 0;
}
