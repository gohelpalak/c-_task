#include <iostream>
using namespace std;

int main() {
    char ch = 'a'; 
    do {
        cout << ch; 

    
        if (ch + 4 <= 'z') {
            cout << ", ";
        }

        ch += 4; 
    } while (ch <= 'z');

    cout << endl; 
    return 0;
}
