// Q.2 Develop a program that prints the given Floyd’s triangle pattern using a nested for
// loop.
// 11
// 12 13
// 14 15 16
// 17 18 19 20

#include <iostream>
using namespace std;
int main()
{
    int start = 11;
    for (int i = 1; i <= 4; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << start << " ";
            start++;
        }
        cout << endl;
    }
    return 0;
}