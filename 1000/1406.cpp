#include <iostream>
#include <string>
using namespace std;

class Node {
  public:
    char data;
    Node *prev;
    Node *next;

    Node(char value) {
        data = value;
        prev = nullptr;
        next = nullptr;
    }
};

class DoublyLinkedList {
  public:
    Node *header;
    Node *trailer;
    DoublyLinkedList() {
        header = new Node('\0');  // 헤더 노드 생성
        trailer = new Node('\0'); // 테일러 노드 생성

        header->next = trailer;
        trailer->prev = header;
    }

    void insertAtEnd(char value) {
        Node *newNode = new Node(value);
        Node *lastNode = trailer->prev;

        lastNode->next = newNode;
        newNode->prev = lastNode;
        newNode->next = trailer;
        trailer->prev = newNode;
    }

    void display() {
        Node *current = header->next;

        while (current != trailer) {
            std::cout << current->data;
            current = current->next;
        }

        std::cout << std::endl;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    DoublyLinkedList ll;
    string str;
    cin >> str;
    for (char ch : str) {
        ll.insertAtEnd(ch);
    }

    Node *cur = ll.trailer->prev; // cur이 위치한 Node의 뒤가 커서 위치라 생각
    int count;
    cin >> count;
    while (count--) {
        cin >> str;
        if (str == "L") {
            if (cur->prev != nullptr)
                cur = cur->prev;
        } else if (str == "D") {
            if (cur->next != ll.trailer)
                cur = cur->next;
        } else if (str == "B") {
            if (cur != ll.header) {
                Node *prev = cur->prev;
                Node *next = cur->next;
                prev->next = next;
                next->prev = prev;
                delete cur;
                cur = prev;
            }
        } else if (str == "P") {
            cin >> str;
            Node *newNode = new Node(str[0]);
            Node *next = cur->next;
            next->prev = newNode;
            newNode->next = next;
            newNode->prev = cur;
            cur->next = newNode;
            cur = cur->next;
        }
    }
    ll.display();

    return 0;
}