#include<iostream>
using namespace std;
int main()
{
    int rows, cols;

    cout << "Enter the number of rows: ";
    cin >> rows;
    cout << "Enter the number of columns: ";
    cin >> cols;

    int arr[rows][cols];

    cout << "Enter the elements of the 2D array:\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> arr[i][j];
        }
    }

    int rowToSum, colToSum;
    cout << "Enter the row index to sum (0 to " << rows - 1 << "): ";
    cin >> rowToSum;
    cout << "Enter the column index to sum (0 to " << cols - 1 << "): ";
    cin >> colToSum;

    if (rowToSum < 0 || rowToSum >= rows || colToSum < 0 || colToSum >= cols) {
        cout << "Invalid row or column index." << endl;
        return 1; 
    }
    cout << "Elements of row " << rowToSum << ": ";
    for (int j = 0; j < cols; j++) {
        cout << arr[rowToSum][j] << " ";
    }
cout << endl;

    cout << "Elements of column " << colToSum << ": ";
    for (int i = 0; i < rows; i++) {
        cout << arr[i][colToSum] << " ";
    }
    cout << endl;

    int rowSum = 0;
    for (int j = 0; j < cols; j++) {
        rowSum += arr[rowToSum][j];
    }
    cout << "Sum of elements in row " << rowToSum << ": " << rowSum << endl;

    int colSum = 0;
    for (int i = 0; i < rows; i++) {
        colSum += arr[i][colToSum];
    }
    cout << "Sum of elements in column " << colToSum << ": " << colSum << endl;

    return 0;

}