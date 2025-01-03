#include <iostream>
using namespace std;
int main()
{
    int score;
    char grade;

    cout << "enter your score";
    cin >> score;

    grade = (score >= 90) ? 'A' :
            (score >= 80) ? 'B' :     
            (score >= 70)   ? 'C':
             (score >= 60)   ? 'D':
              'F';
    cout << "your grade is " << grade << endl;

    switch (grade)
    {
    case 'A':
        cout << "Excellent work!";
        break;
    case 'B':
        cout << "‘Well done";
        break;
    case 'C':
        cout << "Good job";
        break;
    case 'D':
        cout << "‘You Passed, but you could do better";
        break;
    case 'F':
        cout << "‘Sorry, you failed";
        break;
    }

    if(grade=='A' || grade=='B' || grade =='C' || grade =='D' ){
         cout << "Congratulations! You are eligible for the next level." << endl;


    }
    else{
        cout << "Please try again next time." << endl;

    }
    return 0;
}