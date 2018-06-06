// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
using namespace std;

int cntChar(char arr[]){
    int cnt = 0;
    int cur = 0;

    while(arr[cur] != '\0'){
        switch(arr[cur]){
            case ' ':
            case '\n':
            case '\t': 
                break;
            default : cnt++;
        }
        ++cur;
    }
    return cnt;
}

int cntChar2(){
    int cnt = 0;
    char c;
    while(true){
        cin >> c;
        if (c == '$') break;
        ++cnt;
    }
    return cnt;
}


int main(){
    char arr[1000];
    // cin.getline(arr, 990, '$');

    int ans = cntChar2();
    cout << ans;
    ;   ;
}