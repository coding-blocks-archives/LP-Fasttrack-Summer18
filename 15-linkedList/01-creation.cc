// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next; // self referential classes

    Node(int d) {
        data = d;
        next = NULL;
    }
};

Node* createLL() {
    int x;
    Node* head = NULL;
    Node* tail = NULL;

    while (true) {
        cin >> x;
        if (x == -1) break;

        // new int(4)
        Node* newNode = new Node(x);
        if (head == NULL) {
            head = newNode;
            tail = newNode;
        }
        else {
            (*tail).next = newNode;
            tail = tail->next;
        }
    }
    return head;
}

void printLL(const Node* head) {
    // TODO Try with for loop
    const Node* cur = head;
    while (cur) {
        cout << cur->data << "-->";
        // cur->data = 2;
        cur = cur->next;
    }
    cout << endl;
}

??? deleteNode(Node* head, int x){

}

??? reverseList(Node* head){

}

?? reverseList2(Node* head){

}

?? mergeSort(Node* head){

}


int main() {
    Node* head = createLL();
    printLL(head);
    printLL(head);

}