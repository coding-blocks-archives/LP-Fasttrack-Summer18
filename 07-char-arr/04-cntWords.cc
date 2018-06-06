// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
using namespace std;

void print(char label[], int cnt){
    cout << label << ":" << cnt << endl;
}

bool isAlpha(char c){
    return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z');
}

bool isDigit(char c){
    return c >= '0' && c <= '9';
}

bool isWhiteSpace(char c){
    return c == ' ' || c == '\n' || c == '\t';
}

bool isSpace(char c) { 
    return c == ' ';
}

bool isWord(char cur, char previous){
    return isAlpha(cur) && isWhiteSpace(previous);
}

void cntData(int& nchar, int& nword, int& ndigit, int& nother, int& nwhite, int& nspace){
    char cur;
    char previous = ' ';
    while(true){
        cin.get(cur);
        if (cur == '$') break;

        if (isAlpha(cur)){
            ++nchar;
        }
        else if(isDigit(cur)){
            ++ndigit;
        }
        else if(isWhiteSpace(cur)){
            ++nwhite;
            if (isSpace(cur)) ++nspace;
        }
        else {
            ++nother;
        } 
        
        if (isWord(cur, previous)) ++nword;

        previous = cur;       
    }
}

int main(){
    int nChar = 0;
    int nWords = 0;
    int nOther = 0;
    int nWhiteSpace = 0;
    int nSpace = 0;
    int nDigit = 0;

    cntData(nChar, nWords, nDigit, nOther, nWhiteSpace, nSpace);    

    print("nChar", nChar);
    print("nDigit", nDigit);
    print("nWords", nWords);
    print("nOther", nOther);
    print("nWhiteSpace", nWhiteSpace);
    print("nSpace", nSpace);
}