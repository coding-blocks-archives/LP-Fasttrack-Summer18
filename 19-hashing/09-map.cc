// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
#include <map>
using namespace std;
int main(){
    map<string, int> m1, m2; 
    string str;
    int num;

    while(true){
        cin >> str;
        if (str == "exit") break;
        cin >> num;
        m1[str] = num;  // m1["aishwarya"] = 123; // m1.insert("aiswarya", 123);
      
        // if (m["aiswarya"] exists){
            // do something
        // }
    }

    for(map<string, int>::iterator it = m1.begin(); it != m1.end(); ++it){
        cout << it->first << " " << it->second << endl;
    }

}