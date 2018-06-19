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

// void deleteNode(Node*& head, int dataToDelete);

Node* deleteNode(Node* head, int dataToDelete){
    Node* cur = head;
    Node* previous = NULL;
    while(cur){
        if (cur->data == dataToDelete){
            // we have to delete THIS cur node
            if (previous == NULL){
                // it means head is to be deleted
                head = cur->next;
                delete cur;
            }
            else {
                previous->next = cur->next;
                delete cur;
            }
            break;
        }
        else {
            previous = cur;
            cur = cur->next;
        }
    }
    return head;
}

Node* reverseList(Node* head){
    // recursive
    if (head == NULL || head->next == NULL){
        // either 0 or 1 node only in the list
        return head;
    }

    Node* remList = reverseList(head->next);
    head->next->next = head;
    head->next = NULL;
    return remList;
}

Node* reverseList2(Node* head){
    Node* cur = head;
    Node* previous = NULL; 

    while(cur){
        Node* ahead = cur->next;
        cur->next = previous;
        previous = cur;
        cur = ahead;
    }
    return previous;
}

Node* middle(Node* head){
    Node* slow = head;
    Node* fast = head;

    while(slow && fast && fast->next && fast->next->next){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

Node* mergeSortedList(Node* a, Node* b){
    // TODO do iteratively
    if (a == NULL){ // if (!a)
        return b;
    }
    if (b == NULL){
        return a;
    }

    if (a->data < b->data){
        a->next = mergeSortedList(a->next, b);
        return a;
    }
    else {
        b->next = mergeSortedList(a, b->next);
        return b;
    }
}


Node* mergeSort(Node* head){
    if (head == NULL or head->next == NULL){ // if just one node return since problem is not shortened
        return head;
    }

    Node* midPt = middle(head);
    Node* l1 = head;
    Node* l2 = midPt->next;
    midPt->next = NULL;
    l1 = mergeSort(l1);
    l2 = mergeSort(l2);
    head = mergeSortedList(l1, l2);
    return head;
}


int main() {
    Node* head = createLL();
    printLL(head);

    // int x; cin >> x;
    // head = deleteNode(head, x);
    // printLL(head);

    // head = reverseList(head);
    // printLL(head);

    // head = reverseList2(head);
    // printLL(head);

    head = mergeSort(head);
    printLL(head);

}