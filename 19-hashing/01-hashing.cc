// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
using namespace std;

class HashMap {
    class Node {
    public: 
        string key;
        int number;
        Node* next;
        Node(const char* n, int num) {
            key = n;
            number = num;
            next = NULL;
        }
    };
    Node** table; // table-is a- POINTER - to a - POINTER TO A PAIR
    int sze;    // no of nodes int the table
    int capacity;   // capacity of the table

    double loadFactor() {
        return (double)sze / capacity;
    }

    int hashCode(const string& str) {
        int mul = 31;
        int code = 0;
        for (int i = 0; i < str.size(); ++i) {
            code += (str[i] * mul) % capacity;
            code %= capacity;
            mul *= 31;
            mul %= capacity;
        }
        return code;
    }

    void insertIntoTable(Node* newNode) {
        int idx = hashCode(newNode->key);
        Node* &head = table[idx];
        if (head == NULL) {
            head = newNode;
        }
        else {
            // element already exists
            newNode->next = head;
            head = newNode;
        }
        // table[idx] = head;   // head is reference variable
    }

    void rehash() {
        cout << "Rehashing is being done. Currnet Capacity is " << sze << "...\n";
        Node** const oldtable = table;
        table = new Node*[2 * capacity]();
        int oldCapacity = capacity;
        capacity = 2 * capacity;

        for (int i = 0; i < oldCapacity; ++i) {
            Node* head = oldtable[i];
            while (head) {
                Node* tmp = head;
                head = head->next;
                tmp->next = NULL;
                insertIntoTable(tmp);
            }
        }
        delete [] oldtable;
        cout << "Rehashing completed...\n";
    }

public:
    HashMap() {
        capacity = 7;
        table = new Node*[capacity]();  //array initialisation table = {}
        sze = 0;
    }

    void insert(const char* name, int num) {
        Node* curNode = new Node(name, num);
        ++sze;
        insertIntoTable(curNode);
        if (loadFactor() > 0.7) {
            rehash();
        }
    }

    void print() {
        for (int i = 0; i < capacity; ++i) {
            cout << i << ":\t";
            Node* head = table[i];
            while (head) {
                cout << head->key << "(" << head->number << ")" << "-->";
                head = head->next;
            }
            cout << endl;
        }
    }
    // Dtor is must

};


int main() {
    HashMap h;
    h.insert("John", 123);
    h.insert("Johnny", 456);
    h.insert("Yash", 678);
    h.insert("Aishwarya", 1345);
    h.insert("John2", 123);
    h.insert("Johnny2", 456);
    h.insert("Yash2", 678);
    h.insert("Aishwarya2", 1345);
     h.insert("John3", 123);
    h.insert("Johnny3", 456);
    h.insert("Yash3", 678);
    h.insert("Aishwarya3", 1345);
    h.insert("John23", 123);
    h.insert("Johnny23", 456);
    h.insert("Yash23", 678);
    h.insert("Aishwarya23", 1345);
    h.insert("John4", 123);
    h.insert("Johnny4", 456);
    h.insert("Yash4", 678);
    h.insert("Aishwarya4", 1345);
    h.insert("John24", 123);
    h.insert("Johnny24", 456);
    h.insert("Yash24", 678);
    h.insert("Aishwarya24", 1345);
     h.insert("John34", 123);
    h.insert("Johnny34", 456);
    h.insert("Yash34", 678);
    h.insert("Aishwarya34", 1345);
    h.insert("John234", 123);
    h.insert("Johnny234", 456);
    h.insert("Yash234", 678);
    h.insert("Aishwarya234", 1345);
    h.print();
}