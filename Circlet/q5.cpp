// Q.5 Develop a program that prints the given Custom numeric pattern using a nested for loop.
// 5
// 4 5
// 3 4 5
// 2 3 4 5
// 1 2 3 4 5

#include <iostream>
using namespace std;
int main()
{
    int n = 5;
    for (int i = n; i > 0; i--)
    {
        for (int j = i; j <= n; j++)
        {
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}
