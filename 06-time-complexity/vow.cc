// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
using namespace std;

int length(char str[]) {
    int i = 0;
    while (str[i] != '\0') {
        ++i;
    }
    return i;
}

char toLower(char c) {
    return (c >= 'A' && c <= 'Z') ? 'a' + (c - 'A') : c;
}

bool isVow(char c) {
    /*return
        c == 'a' || c == 'A' ||
        c == 'e' || c == 'E' ||
        c == 'i' || c == 'I' ||
        c == 'o' || c == 'O' ||
        c == 'u' || c == 'U';*/

    switch (toLower(c)) {
    case 'a':
    case 'e':
    case 'i':
    case 'o':
    case 'u': return true;
    }
    return false;
}


int cntVow(char str[]) {
    int len = length(str);
    int cnt = 0;

    for (int i = 0; i < len; ++i) {
        if (isVow(str[i])) {
            ++cnt;
        }
    }
    return cnt;
}

int main() {
    char str[100];
    // cin >> str;
    cin.getline(str, 90, '\n');

    int ans = cntVow(str);
    cout << ans;
}