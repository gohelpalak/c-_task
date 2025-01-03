// Q.4 Develop a program that prints the given Full Pyramid pattern using a nested for loop.
//         5
//       4 5 4
//     3 4 5 4 3
//   2 3 4 5 4 3 2
// 1 2 3 4 5 4 3 2 1

#include <iostream>
using namespace std;

int main()
{
    int rows = 5;

    for (int i = 1; i <= 5; i++)
    {

        for (int k = 1; k <= 5 - i; k++)
        {
            cout << "  ";
        }

        for (int k = 5 - i + 1; k <= 5; k++)
        {
            cout << k << " ";
        }

        for (int j = 5 - 1; j >= 5 - i + 1; j--)
        {
            cout << j << " ";
        }

        cout << endl;
    }

 return 0;
}