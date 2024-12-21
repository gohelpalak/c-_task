// Q.6 Develop a program that prints the given pattern using a nested for loop.
//         1
//       2 1
//     3 2 1
//   4 3 2 1
// 5 4 3 2 1
#include <iostream>
using namespace std;

int main() {
    int rows = 5; 

    for (int i = 1; i <= rows; i++) { 
        for (int k = 1; k <= rows - i; k++) {
            cout << "  ";
        }

       
        for (int j = i; j >= 1; j--) {
            cout << j << " ";
        }

        cout << endl; 
    }

    return 0;
}