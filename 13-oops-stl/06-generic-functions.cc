// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
using namespace std;


template<typename T, typename Y>
void bubbleSort(T arr[], int n, Y compare){
    for(int i = 0; i < n - 1; ++i){
        for(int cur = 0; cur < n - i - 1; ++cur){
            if (compare(arr[cur], arr[cur+1])){
                // it returns true if arr[i] > arr[i + 1]
                swap(arr[cur], arr[cur + 1]);
            }
        }
    }
}



class Elephant{
public:
    int wt;
    char name[20];
};

bool compareMyElepnant(Elephant A, Elephant B){
    return A.wt > B.wt;
}

bool compareInt(int x, int y){
    return x > y;
}

template<typename T, typename Y >
void print(T arr[], int n, Y printCriteria){
    for(int i = 0; i < n; ++i){
        // cout << arr[i] << " ";
        printCriteria(arr[i]);  // element
    }
    cout << endl;
}

void printMyElephant(Elephant E){
    cout << E.wt << " " << E.name << endl;
}

void printInt(int x){
    cout << x << " ";
}

int main() {
    int arr_int[] = {3,2,1};
    char arr_char[] = {'a','b','c'};

    // bubbleSort(arr_char, 3, compareInt);
    // print<char>(arr_char, 3);
    // cout << endl;

    bubbleSort(arr_int, 3, compareInt);
    print(arr_int, 3, printInt);
    cout << endl;

    Elephant E[] = {
        {1600, "Hachi"},
        {1500, "Rocky"},
        {1000, "Jumbo"}
    };
    
    bubbleSort(E, 3, compareMyElepnant);
    print(E, 3, printMyElephant);

}