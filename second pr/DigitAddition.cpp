#include <iostream>
using namespace std;

int main() {
    int number, firstDigit, lastDigit;
    
    cout << "Enter any number: ";
    cin >> number;

    
    number = abs(number);

    lastDigit = number % 10; 

    
    while (number >= 10) {
        number /= 10;
    }
    firstDigit = number;

   
    int sum = firstDigit + lastDigit;

    cout << "The sum of the first and the last digit: " << sum << endl;

    return 0;
}
