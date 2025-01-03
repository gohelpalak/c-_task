// Q.2 Largest Element in 2D Array


#include<iostream>
using namespace std;

int main()
{
    int row, col;

    cout << "Enter the number of rows: ";
    cin >> row;
    cout << "Enter the number of columns: ";
    cin >> col;

    int arr[row][col]; 

    cout << "Enter the elements of the 2D array:\n";
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cin >> arr[i][j];
        }
    }

    int largest = arr[0][0];

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (arr[i][j] > largest) {
                largest = arr[i][j];
            }
        }
    }

    cout << "The largest element in the 2D array is: " << largest << endl;

    return 0;
}