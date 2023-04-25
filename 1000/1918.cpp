#include <iostream>
#include <stack>
#include <string>
using namespace std;

int getPriority(char c) {
    if (c == '(')
        return 0;
    if (c == '+' || c == '-')
        return 1;
    if (c == '*' || c == '/')
        return 2;
    return -1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    string qr;
    stack<char> st;
    cin >> qr;
    for (int i = 0; i < qr.size(); i++) {
        if (qr[i] >= 'A' && qr[i] <= 'Z') {
            cout << qr[i];
        } else if (qr[i] == '(') {
            st.push('(');
        } else if (qr[i] == ')') {
            while (st.top() != '(') {
                cout << st.top();
                st.pop();
            }
            st.pop();
        } else {
            while (!st.empty() && getPriority(st.top()) >= getPriority(qr[i])) {
                cout << st.top();
                st.pop();
            }
            st.push(qr[i]);
        }
    }
    while (!st.empty()) {
        cout << st.top();
        st.pop();
    }

    return 0;
}
