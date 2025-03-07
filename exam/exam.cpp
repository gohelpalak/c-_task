#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};


class LinkedList {
public:
    Node* head;
    LinkedList() { head = nullptr; }

    void insert(int value) {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = nullptr;
    
        if (!head) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }
    void update(int oldVal, int newVal) {
        Node* temp = head;
        while (temp) {
            if (temp->data == oldVal) {
                temp->data = newVal;
                return;
            }
            temp = temp->next;
        }
        cout << "Value not found in the list." << endl;
    }

    void display() {
        Node* temp = head;
        while (temp) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }

    void merge(int arr[], int left, int mid, int right) {
        int n1 = mid - left + 1, n2 = right - mid;
        int L[n1], R[n2];
        for (int i = 0; i < n1; i++) L[i] = arr[left + i];
        for (int i = 0; i < n2; i++) R[i] = arr[mid + 1 + i];
    
        int i = 0, j = 0, k = left;
        while (i < n1 && j < n2) arr[k++] = (L[i] <= R[j]) ? L[i++] : R[j++];
        while (i < n1) arr[k++] = L[i++];
        while (j < n2) arr[k++] = R[j++];
    }
    
   
    void mergeSort(int arr[], int left, int right) {
        if (left < right) {
            int mid = left + (right - left) / 2;
            mergeSort(arr, left, mid);
            mergeSort(arr, mid + 1, right);
            merge(arr, left, mid, right);
        }
    }

    int partition(int arr[], int low, int high) {
        int pivot = arr[high];
        int i = (low - 1);
        for (int j = low; j < high; j++) {
            if (arr[j] < pivot) {
                swap(arr[++i], arr[j]);
            }
        }
        swap(arr[i + 1], arr[high]);
        return (i + 1);
    }
    void quickSort(int arr[], int low, int high) {
        if (low < high) {
            int pi = partition(arr, low, high);
            quickSort(arr, low, pi - 1);
            quickSort(arr, pi + 1, high);
        }
    }
    
    int binarySearch(int arr[], int size, int key) {
        int left = 0, right = size - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (arr[mid] == key) return mid;
            if (arr[mid] < key) left = mid + 1;
            else right = mid - 1;
        }
        return -1;
    }

   
    
    
    
};


int main() {
    LinkedList list;
    int choice;
    do {
        cout << "\nMenu:\n";
        cout << "1. Insert into Linked List\n";
        cout << "2. Update Linked List Value\n";
        cout << "3. Display Linked List\n";
        cout << "4. Sort an Array (Merge Sort)\n";
        cout << "5. Sort an Array (Quick Sort)\n";
        cout << "6. Binary Search in Sorted Array\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            int val;
            cout << "Enter value: ";
            cin >> val;
            list.insert(val);
        } else if(choice == 2){
            int oldVal, newVal;
                cout << "Enter value to update: ";
                cin >> oldVal;
                cout << "Enter new value: ";
                cin >> newVal;
                list.update(oldVal, newVal);

        }else if (choice == 3) {
            list.display();
        } else if(choice==4){
           int n;
            cout << "Enter the number of elements: ";
            cin >> n;
            int arr[n];
            for (int i = 0; i < n; i++) {
                cout << "Enter element " << i + 1 << ": ";
                cin >> arr[i];
            }
            list.mergeSort(arr, 0, n - 1);
            cout << "Sorted array: ";
            for (int i = 0; i < n; i++) {
                cout << arr[i] << " ";
            }
            cout << endl;

        }else if(choice==5){
            int n;
            cout << "Enter the number of elements: ";
            cin >> n;
            int arr[n];
            for (int i = 0; i < n; i++) {
                cout << "Enter element " << i + 1 << ": ";
                cin >> arr[i];
            }
            list.quickSort(arr, 0, n - 1);
            cout << "Sorted array: ";
            for (int i = 0; i < n; i++) {
                cout << arr[i] << " ";
            }
            cout << endl;
            
        } else if(choice==6){
            int n;
            cout << "Enter the number of elements: ";
            cin >> n;
            int arr[n]; 
            for (int i = 0; i < n; i++) {
                cout << "Enter element " << i + 1 << ": ";
                cin >> arr[i];
            }
            int key;
            cout << "Enter the key to search: ";
            cin >> key;
            int index = list.binarySearch(arr, n, key);
            if (index != -1) {
                cout << "Key found at index " << index << endl;
            } else {
                cout << "Key not found in the array." << endl;
            }
        }
    } while (choice != 7);

    return 0;
}