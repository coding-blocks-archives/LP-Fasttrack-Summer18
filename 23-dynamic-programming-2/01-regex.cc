// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
#include <cstring>
using namespace std;

bool regexMatch(char str[], char pattern[]) {
    int lenStr = strlen(str);
    int lenPattern = strlen(pattern);
    bool dp[110][110];

    for (int i = 0; i <= lenPattern; ++i) {
        for (int j = 0; j <= lenStr; ++j) {
            if (i == 0 and j == 0) { 
                dp[i][j] = true; 
            }
            else if (i == 0) {
                // emptiness matches blah blah blah...
                dp[i][j] = false;
            }
            else if (j == 0) {
                // empty STRING matches PatternSoFar starting from 0 till j
                char curChar = pattern[i - 1];
                dp[i][j] = (dp[i - 1][j] && curChar == '*');
            }
            else {
                // i and j refers to NON SENTINEL THINGS
                char curCharInPattern = pattern[i - 1];
                char curCharInString = str[j - 1];
                if (curCharInPattern == '?') {
                    dp[i][j] = dp[i - 1][j - 1];
                }
                else if (curCharInString == curCharInPattern) {
                    dp[i][j] = dp[i - 1][j - 1];

                }
                else if (curCharInPattern == '*') {
                    dp[i][j] = dp[i][j - 1] or dp[i - 1][j];
                }
                else {
                    // curCharInPattern is NEITHER *, ? or same as curCharInString
                    // hence the string WILL NOT MATCH
                    dp[i][j] = false;
                }
            }
        }
    }
    return dp[lenPattern][lenStr];  // lenPattern = (abc) 3 but idx is upto 2 only
}



int main() {
    char str[100], pattern[100];
    // cin >> str >> pattern;

    cin.getline(str, 90);
    cin.getline(pattern, 90);
    cout << "X" << str << "X" << endl;
    cout << "X" << pattern << "X" << endl;
    bool ans = regexMatch(str, pattern);
    cout << ans;
}