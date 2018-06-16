// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
#include <cstring>  // string.h
using namespace std;

class Pen {
public:
    char name[25];
    char color[25];

    void mywrite(char words[]) {
        cout << name << "is writing " << words << " " << "with " << color
             << " color";
    }
};



class Car {
public:
    char name[25];
    int enginePowerinHP;
};

int main() {
    // char pen[] = "Parker";
    // char color[] = "black";

    Pen P1, P2;
    strcpy(P1.name, "Parker");     // P1.name = "Parker";
    strcpy(P1.color, "black");

    char words[] = "Writing makes you exact!";

    // mywrite(P1, words);

    P1.mywrite(words);

    Car C;
    mywrite(C, words);
}