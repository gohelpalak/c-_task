#include <iostream>
using namespace std;


class StackBase {
public:
    virtual void push(int value) = 0;
    virtual void pop() = 0;
    virtual int top() const = 0;
    virtual bool isEmpty() const = 0;
    virtual bool isFull() const = 0;
    virtual void display() const = 0;
};


class Stack : public StackBase {
private:
    static const int SIZE = 5; 
    int arr[SIZE];  
    int topIndex;   

public:
    
    Stack() : topIndex(-1) {}

    // Push an element 
    void push(int value) override {
        if (isFull()) {
            cout << "Stack Overflow! Cannot push " << value << endl;
            return;
        }
        arr[++topIndex] = value;
        cout << value << " pushed onto the stack." << endl;
    }

    // Pop an element 
    void pop() override {
        if (isEmpty()) {
            cout << "Stack Underflow! Cannot pop." << endl;
            return;
        }
        cout << arr[topIndex--] << " popped from the stack." << endl;
    }

    // Get the top element without removing it
    int top() const override {
        if (isEmpty()) {
            cout << "Stack is empty. No top element." << endl;
            return -1;
        }
        return arr[topIndex];
    }

    // stack is empty
    bool isEmpty() const override {
        return topIndex == -1;
    }

    // stack is full
    bool isFull() const override {
        return topIndex == SIZE - 1;
    }

    // Display stack 
    void display() const override {
        if (isEmpty()) {
            cout << "Stack is empty." << endl;
            return;
        }
        cout << "Stack elements: ";
        for (int i = 0; i <= topIndex; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    Stack s;
    int choice, value;

    do {
        cout << "\n===== Stack Menu =====\n";
        cout << "1. Push an element\n";
        cout << "2. Pop an element\n";
        cout << "3. Display top element\n";
        cout << "4. Check if stack is empty\n";
        cout << "5. Check if stack is full\n";
        cout << "6. Display stack elements\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to push: ";
                cin >> value;
                s.push(value);
                break;
            case 2:
                s.pop();
                break;
            case 3:
                cout << "Top element: " << s.top() << endl;
                break;
            case 4:
                cout << (s.isEmpty() ? "Stack is empty." : "Stack is not empty.") << endl;
                break;
            case 5:
                cout << (s.isFull() ? "Stack is full." : "Stack is not full.") << endl;
                break;
            case 6:
                s.display();
                break;
            case 7:
                cout << "Exiting program...\n";
                break;
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    } while (choice != 7);

    return 0;
}