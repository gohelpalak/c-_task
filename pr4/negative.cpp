// Q.1 Negative Elements in 1D Array

#include<iostream>
using namespace std;
int main()
{
   int n;
    cout << "Enter the size of array: ";
    cin >> n; 
    int arr[n]; 

    cout << "Enter " << n << " elements ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Negative elements in the array: ";
    bool found = false; 

    for (int i = 0; i < n; i++) {
        if (arr[i] < 0) {
        cout << arr[i] << " ";
            found = true;
        }
    }

    if (!found) {
        cout << "None";
    }
    cout << endl;

    return 0;
}