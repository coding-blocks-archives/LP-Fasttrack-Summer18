// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
#include <cstring>
using namespace std;
#define LABEL(x, val) cout << "Updated Value of " << (#x) << " " << (val)\
        << endl

class Person{
    int age;
public:
    char name[40];
    Person(int k, const char n[]){ // const char * n // char * const n
        age = k;
        // n[2] = 'k'; // (*(n + 2) = 'k')
        // name = n;
        strcpy(name, n);

    }
    void print(){
        cout << name << ":" << age << endl;
    }
};
int main(){
       Person P1(20, "Johnny");
       P1.print();            // Johnny : 20

       Person P2 = P1;
       P2.print();            //Johnny : 20
       
       P2.name[0] = 'T';
       LABEL(P2, P2.name);      // Tohnny
       LABEL(P1, P1.name);      // Johnny
}