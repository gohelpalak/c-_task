#include <iostream>
#include <vector>
using namespace std;

// Selection Sort
void selectionSort(vector<int> &arr)
{
    int n = arr.size();
    for (int i = 0; i < n - 1; i++)
    {
        int minIndex = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[minIndex])
            {
                minIndex = j;
            }
        }
        swap(arr[i], arr[minIndex]);
    }
}

// Merge Sort
void merge(vector<int> &arr, int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;
    vector<int> L(n1), R(n2);

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(vector<int> &arr, int left, int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

// Linear Search
int linearSearch(const vector<int> &arr, int key)
{
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] == key)
            return i;
    }
    return -1;
}

// Binary Search
int binarySearch(const vector<int> &arr, int key)
{
    int left = 0, right = arr.size() - 1;
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (arr[mid] == key)
            return mid;
        else if (arr[mid] < key)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;
}

// Menu-driven Program
int main()
{
    vector<int> arr;
    int choice, n, key;

    do
    {
        cout << "\nMenu:\n";
        cout << "1. Enter array\n2. Selection Sort\n3. Merge Sort\n4. Linear Search\n5. Binary Search\n6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter number of elements: ";
            cin >> n;
            arr.resize(n);
            cout << "Enter elements: ";
            for (int i = 0; i < n; i++)
                cin >> arr[i];
            break;
        case 2:
            selectionSort(arr);
            cout << "Array after Selection Sort: ";
            for (int num : arr)
                cout << num << " ";
            cout << endl;
            break;
        case 3:
            mergeSort(arr, 0, arr.size() - 1);
            cout << "Array after Merge Sort: ";
            for (int num : arr)
                cout << num << " ";
            cout << endl;
            break;
        case 4:
            cout << "Enter element to search (Linear Search): ";
            cin >> key;
            if (linearSearch(arr, key) != -1)
                cout << "Element found at index " << linearSearch(arr, key) << endl;
            else
                cout << "Element not found." << endl;
            break;
        case 5:
            cout << "Enter element to search (Binary Search): ";
            cin >> key;
            if (binarySearch(arr, key) != -1)
                cout << "Element found at index " << binarySearch(arr, key) << endl;
            else
                cout << "Element not found." << endl;
            break;
        case 6:
            cout << "Exiting program." << endl;
            break;
        default:
            cout << "Invalid choice, please try again." << endl;
        }
    } while (choice != 6);

    return 0;
}