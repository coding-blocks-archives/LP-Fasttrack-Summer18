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
    char* name;
    Person(int k, const char n[]){ // const char * n // char * const n
        age = k;
        int len = strlen(n);
        name = new char[len];
        strcpy(name, n);

    }

    Person(Elepant& E){

    }


    void print(){
        cout << name << ":" << age << endl;
    }

    Person(const Person& p){
        age = p.age;
        name = new char[strlen(p.name)];
        strcpy(name, p.name);
    }
    Person(){
        age = 0;
        name = NULL;
    }
};

void foo(){
    // Person P1; // ERROR Hidden ctor
}

int main(){
       Person P;

       Person P1(20, "Johnny");
       P1.print();            // Johnny : 20

       Person P2 = P1;      // Person P2(P1);       P2.initialiseWith(P1)
       P2.print();            //Johnny : 20
       
       P2.name[0] = 'T';
       LABEL(P2, P2.name);      // Tohnny
       LABEL(P1, P1.name);      // Johnny

       foo(); foo(); foo();
}