// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
#include <vector>
#include <climits>
using namespace std;
#define print(x) cout << #x << " " << x << endl

class Heap {
    vector<int> v;
    int cnt;
    int left(int i) { return 2 * i; }
    int right(int i) {return 2 * i + 1;}
    int parent(int i) {return i / 2;}

    void heapify(int i){
        int maxIndex = i;
        if (left(i) < v.size() && v[left(i)] > v[i]){
            maxIndex = left(i);
        }

        if (right(i) < v.size() && v[right(i)] > v[maxIndex]){
            maxIndex = right(i);
        }
        if (i != maxIndex){
            swap(v[i], v[maxIndex]);
            heapify(maxIndex);
        }
    }

public:
    Heap() {
        v.push_back(INT_MIN); // sentinel
        cnt = 0;
    }

    void push(int x) {
        v.push_back(x); ++cnt;
        int i = v.size() - 1;

        while(i > 1 && v[parent(i)] < v[i]){
            swap(v[parent(i)], v[i]);
            i = parent(i);
        }
    }

    int top(){
        if (cnt == 0) return INT_MIN;  // -inf
        return v[1];
    }

    int size(){ return cnt; }

    void pop(){
        if (cnt < 1) return; 
        swap(v[1], v[cnt]);
        v.pop_back();
        heapify(1);
        --cnt;
    }
};


int main() {
    Heap H;
    H.push(2);
    print(H.top());
    H.push(7);
    H.push(11);
    print(H.top());
    H.pop();
    H.push(56);
    H.push(101);
    H.push(-11);
    H.pop();
    print(H.top());
    H.push(-11);
    H.pop();
    H.pop();
    H.pop();
    print(H.top());
}