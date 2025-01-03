#include <iostream>
using namespace std;

int main() {
    int number, count = 0;

    cout << "Enter any number: ";
    cin >> number;

    number = abs(number);

    for ( number ; number != 0; number /= 10) {
        count++;
    }

    cout << "Total number of digits: " << count << endl;

    return 0;
}
