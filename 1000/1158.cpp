#include <iostream>
using namespace std;

struct Node {
    Node *next;
    int data;
};

int main() {
    int n, k;
    cin >> n >> k;
    Node *start = new Node;
    start->data = 1;
    Node *cur = start;
    for (int i = 2; i <= n; i++) {
        Node *temp = new Node;
        temp->data = i;
        cur->next = temp;
        cur = temp;
    }
    cur->next = start;
    cout << '<';

    while (true) {
        if (cur->next == cur) {
            cout << cur->data << '>';
            break;
        }
        for (int i = 0; i < k - 1; i++) {
            cur = cur->next;
        }
        Node *temp = cur;
        cur = cur->next;
        cout << cur->data << ", ";
        temp->next = cur->next;
        delete cur;
        cur = temp;
    }

    return 0;
}
