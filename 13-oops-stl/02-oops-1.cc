// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
using namespace std;

void mywrite(char pen[], char words[], char color[]){
    cout << pen << "is writing " << words << " " << "with " << color
         << " color"; 
}

class Pen{
public:
    char name[25];
    char color[25];
}

int main(){
    char pen[] = "Parker";
    char color[] = "black";
    char words[] = "Writing makes you exact!";

    mywrite(pen, words, color);

    char car[] = "wagorR";
    mywrite(car, words, color);
}