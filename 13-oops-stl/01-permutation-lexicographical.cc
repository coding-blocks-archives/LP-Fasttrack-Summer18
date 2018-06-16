// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
#include <vector>
#include <string>
using namespace std;
int cnt = 0;

bool compareString(string A, string B){
    for(int i = 0, j = 0; i < A.size() && j < B.size(); ++i, ++j){
        // if (A[i] > B[j]) return true;
        // else if (A[i] < B[j]) return false;

        if (A[i] != B[j]) return A[i] > B[j];

    }
    return true;
}

template<typename T, typename Y>
void bubbleSort(T& arr, int n, Y compare){
    for(int i = 0; i < n - 1; ++i){
        for(int cur = 0; cur < n - i - 1; ++cur){
            if (compare(arr[cur], arr[cur+1])){
                // it returns true if arr[i] > arr[i + 1]
                swap(arr[cur], arr[cur + 1]);
            }
        }
    }
}



void printPermutations(char arr[], int be, vector<string>& ans){
    if (arr[be] == '\0'){
        // ++cnt;
        // cout <<cnt << ".\t" << arr << endl;
        ans.push_back(arr);
        return;
    }

    for(int pos = be; arr[pos] != '\0'; ++pos){
        swap(arr[pos], arr[be]);
        printPermutations(arr, be + 1, ans);
        swap(arr[pos], arr[be]);
    }
}



int main(){
    char arr[100];
    cin >> arr;
    
    vector<string> ans;
    cout << "before permutations " << ans.size() << endl;
    printPermutations(arr, 0, ans);
    cout << "after permutations " << ans.size() << endl;

    bubbleSort(ans, ans.size(), compareString);

    for(int i = 0; i < ans.size(); ++i){
        cout << ans[i] << endl;
    }

}