// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
#include <stack>
#include <map>
#include <vector>
using namespace std;
void inputArr(int arr[], int n) {
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
}
void outputArr(int arr[], int n) {
    for (int i = 0; i < n; ++i) {
        cout << arr[i] << " ";
    }
}

int* stockSpan(int arr[], int n) {
    int* ans = new int[n];
    typedef int index;
    stack<index> s;

    for (int i = 0; i < n; ++i) {
        int curPrice = arr[i];
        while (s.empty() == false and arr[s.top()] < curPrice) { s.pop(); }
        ans[i] = s.empty() ? 0 : i - s.top();
        s.push(i);
    }
    return ans;
}


int rainWater(int arr[], int n) {
    int ans = 0;
    int be = 0;
    int en = n - 1;
    int inf = 1e9;
    int leftMax = -inf;
    int rightMax = -inf;

    while (be <= en) {
        if (arr[be] > leftMax) {
            leftMax = arr[be];
            ++be;
        }
        else if (arr[en] > rightMax) {
            rightMax = arr[en];
            --en;
        }
        else if (leftMax < rightMax) {
            // compute area of the be bar
            ans += (leftMax - arr[be]);
            ++be;
        }
        else {
            // compute area in the en bar
            ans += (rightMax - arr[en]);
            --en;
        }
    }
    return ans;
}

vector<int> distinctElements(int arr[], int n, int k) {
    map<int, int> m;    // element, cnt
    vector<int> v;

    for (int i = 0; i < n; ++i) {
        if (i < k) {
            // first window
            if (m.find(arr[i]) == m.end()) {
                // element is not in the map
                m.insert(make_pair(arr[i], 1));
            }
            else {
                m[arr[i]] += 1;
            }
            if (i == k - 1) v.push_back(m.size());
        }
        else {
            // next windows
            int elementBeforeWindowStart = arr[i - k];
            int elementAtWindowEnd = arr[i];

            m[elementBeforeWindowStart] -= 1;
            if (m[elementBeforeWindowStart] == 0) {
                m.erase(elementBeforeWindowStart);
            }
            m[elementAtWindowEnd] += 1;
            v.push_back(m.size());
        }
    }
    return v;
}

int main() {
    int n; cin >> n;
    int arr[100];
    inputArr(arr, n);

    // auto ans = stockSpan(arr, n);
    // outputArr(ans, n);
    // delete [] ans;

    // int ans = rainWater(arr, n);
    // cout << ans << endl;

    int k; cin >> k;
    auto ans = distinctElements(arr, n, k);
    for (int x : ans) {cout << x << " ";} cout << endl;
}