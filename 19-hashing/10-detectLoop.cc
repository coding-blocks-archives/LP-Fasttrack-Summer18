// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
#include <map>
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

Node* detectCycle(Node* head){
    map<Node*, bool> m;

    Node* cur = head;
    while(cur){
        if (m.find(cur) != m.end()){
            // cur is in the list
            return cur;
        }
        m.insert(make_pair(cur, true));
        cur = cur->next;
    }
    return NULL;
}


int main(){
    Node* head = createLL();
    head->next->next->next->next->next = head->next->next;
    Node* ans =  detectCycle(head);
    if (ans) cout << ans << " " << ans->data << endl;


}