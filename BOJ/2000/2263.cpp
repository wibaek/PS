#include <iostream>
using namespace std;

int n;
int inOrder[100001];
int postOrder[100001];

void traversal(int inStart, int inEnd, int postStart, int postEnd) {
    int root = postOrder[postEnd];
    if (inStart > inEnd)
        return;
    cout << root << " ";
    if (inStart == inEnd)
        return;

    int locate = -1;
    for (int i = inStart; i <= inEnd; i++) {
        if (inOrder[i] == root) {
            locate = i;
            break;
        }
    }
    int size = locate - inStart;
    traversal(inStart, inStart + size - 1, postStart, postStart + size - 1);
    traversal(inStart + size + 1, inEnd, postStart + size, postEnd - 1);
}

int main() {
    // Input
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> inOrder[i];
    for (int i = 1; i <= n; i++)
        cin >> postOrder[i];

    traversal(1, n, 1, n);
}