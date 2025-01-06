
#include <iostream>
using namespace std;
int calculator(){
    int choice, num1, num2;
    while (1)
    {
        cout << "Press 1 for +\n Press 2 for -\nPress 3 for *\n Press 4 for /\nPress 5 for %\nPress 0 for the exit\n";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter the first number: ";
            cin >> num1;
            cout << "Enter the second number: ";
            cin >> num2;
            cout << "Addition of " << num1 << " and " << num2 << " is " << num1 + num2 << endl;
            break;
        case 2:
            cout << "Enter the first number: ";
            cin >> num1;
            cout << "Enter the second number: ";
            cin >> num2;
            cout << "Subtraction of " << num1 << " and " << num2 << " is " << num1 - num2 << endl;
            break;
        case 3:
            cout << "Enter the first number: ";
            cin >> num1;
            cout << "enter the second number: ";
            cin >> num2;
            cout << "Multiplication of " << num1 << "and " << num2 << " is " << num1 * num2 << endl;
            break;
        case 4:
            cout << "Enter the first number: ";
            cin >> num1;
            cout << "enter the second number: ";
            cin >> num2;
            if (num2 == 0)
            {
                cout << "Division of " << num1 << "and " << num2 << " is undefined" << endl;
            }
            else
            {
                cout << "Division of " << num1 << "and " << num2 << " is " << num1 / num2 << endl;
            }
            break;
        case 5:
            cout << "Enter the first number: ";
            cin >> num1;
            cout << "Enter the second number: ";
            cin >> num2;
            if (num2 == 0)
            {
                cout << "Modulo of " << num1 << "and " << num2 << " is undefined" << endl;
            }
            else
            {
                cout << "Modulo of " << num1 << "and " << num2 << " is " << num1 % num2 << endl;
            }
            break;
        case 0:
            cout << "Exiting the program" << endl;
            break;
        default:
        {
            cout << "Invalid choice" << endl;
            cout << "Please enter a valid choice from 1 to 5" << endl;
        }
        break;
        }
        }


    return 0;
}

int main(){
    calculator();
    return 0;

}



