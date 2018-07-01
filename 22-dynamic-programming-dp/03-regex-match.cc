// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
using namespace std;

bool regexMatch(char str[], int be, char pattern[], int i) {
    if (str[be] == '\0' and pattern[i] == '\0') { return true; }

    if (pattern[i] == '\0') { return false; }

    if (str[be] == '\0') {
        if (pattern[i] == '*') {
            return regexMatch(str, be, pattern, i + 1);
        }
        else {
            return false;
        }
    }

    // we are SURE that one char in both pattern and string exists
    if (pattern[i] == '?' or pattern[i] == str[be]) {
        return regexMatch(str, be + 1, pattern, i + 1);
    }

    if (pattern[i] == '*') {
        return
            /*match atleast one char*/
            regexMatch(str, be + 1, pattern, i) or
            /*match zero char*/
            regexMatch(str, be, pattern, i + 1);
    }

    // NOW pattern[i] is neither * nor ? nor str[be]
    return false;
}


int main() {
    char str[100], pattern[100];
    cin >> str >> pattern;
    bool ans = regexMatch(str, 0, pattern, 0);
    cout << ans;
}