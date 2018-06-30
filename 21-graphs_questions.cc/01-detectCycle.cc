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
    const Node* cur = head;
    while (cur) {
        cout << cur->data << "-->"; cur = cur->next;
    }
    cout << endl;
}

Node* detectCylce(Node* head) {
    Node* slow = head;
    Node* fast = head;
    while (slow && fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) break;
    }
    return fast;
    if (fast && fast->next == NULL) return NULL;
}

void removeLoop(Node* head){
    Node* meetingPoint = detectCylce(head);
    Node* start = head;
    while(meetingPoint && start && start->next != meetingPoint->next){
        start = start->next;
        meetingPoint = meetingPoint->next;
    }
    if (meetingPoint) meetingPoint->next = NULL;
}

int main() {
    Node* head = createLL(); // insert 9 elements
    // construct a loop
    Node* tail = head;
    while (tail->next) { tail = tail->next; }
    tail->next = head->next->next->next;

    Node* loopNode = detectCylce(head);
    cout << loopNode << " " << (loopNode ? loopNode->data : -1);
    removeLoop(head);
    printLL(head);

}