// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
#include <stack>
#include <string>
#include <vector>
using namespace std;

void printStk(stack<int>& stk) {
    // pass by reference. Objects BY DEFAULT via Pass by Value
    while (stk.empty() == false) {
        cout << stk.top() << " " ;
        stk.pop();
    }
    cout << endl;
}

bool isOperator(char c) {
    switch (c) {
    case '+':
    case '-':
    case '/':
    case '*': return true;
    }
    return false;
}
bool isBracket(char c) {
    return c == '(' or c == ')';
}

int redundantParantheses(const string& str) {
    stack<char> s;
    int cnt = 0;
    for (int i = 0; i < str.size(); ++i) {
        char cur = str[i];
        if (isOperator(cur) == false and isBracket(cur) == false) continue;

        if (isOperator(cur) && s.empty() == false) {
            s.push(cur);
        }
        if (cur == '(') s.push(cur);
        if (cur == ')') {
            bool isRedundant = true;
            while (s.empty() == false && s.top() != '(') {
                isRedundant = false;
                s.pop();
            }
            s.pop();
            if (isRedundant) ++cnt;
        }
    }
    return cnt;
}

//=======================
vector<int> nearestLargest(const vector<int>& arr) { // towards left
    int n = arr.size();
    stack<int> s;
    vector<int> ans(n);

    for (int i = 0; i < arr.size(); ++i) {
        int cur =  arr[i];
        while (s.empty() == false && s.top() <= cur) {
            s.pop();
        }
        ans[i] = s.empty() ? -1 : s.top();  
        // ans.push_back(s.empty() ? -1 : s.top())
        s.push(cur);
    }
    return ans;
}

//=======================
void emptyStack(stack<int>& from, stack<int>& to) {
    while (from.empty() == false) {
        to.push(from.top());
        from.pop();
    }
}

void reverseStack2(stack<int>& s) {
    stack<int> s1, s2;
    emptyStack(s, s1);
    emptyStack(s1, s2);
    emptyStack(s2, s);
}

// ??? reverseStack1(){}
// ??? reverseStack0(){}

//=======================

template <typename T>
void inputVec(T& v) {
    for (int i = 0; i < v.size(); ++i) {
        cin >> v[i];
    }
}

int main() {
    // stack<int> s;

    // int x;
    // while(true){
    //     cin >> x;
    //     if (x == -1)break;
    //     s.push(x);
    // }
    // printStk(s);

    // string s;
    // cin >> s;
    // int ans = redundantParantheses(s);
    // cout << ans;

    int n; cin >> n;
    vector<int> arr(n);
    inputVec(arr);
    auto ans = nearestLargest(arr); // auto = vector<int>
    for (int x : ans) {cout << x << " ";}
}