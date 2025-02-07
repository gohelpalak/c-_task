
#include <iostream>
#include <vector>

using namespace std;

class Student {
public:
    int id;
    string name;

    
    Student(int studentId, string studentName) : id(studentId), name(studentName) {}

   
    void display() const {
        cout << "ID: " << id << ", Name: " << name << endl;
    }
};

class StudentManagement {
private:
    vector<Student> students;

public:
    
    void addStudent(int id, const string& name) {
        students.push_back(Student(id, name));
        cout << "Student added successfully!\n";
    }

    
    void displayStudents() const {
        if (students.empty()) {
            cout << "No students found!\n";
            return;
        }
        for (const auto& student : students) {
            student.display();
        }
    }

    
    void removeStudent(int id) {
        for (auto it = students.begin(); it != students.end(); ++it) {
            if (it->id == id) {
                students.erase(it);
                cout << "Student removed successfully!\n";
                return;
            }
        }
        cout << "Student with ID " << id << " not found!\n";
    }

    
    void searchStudent(int id) const {
        for (const auto& student : students) {
            if (student.id == id) {
                cout << "Student found: ";
                student.display();
                return;
            }
        }
        cout << "Student with ID " << id << " not found!\n";
    }
};

int main() {
    StudentManagement sm;
    int choice, id;
    string name;

    do {
        cout << "\nStudent Management System";
        cout << "\n1. Add Student";
        cout << "\n2. Display All Students";
        cout << "\n3. Remove Student by ID";
        cout << "\n4. Search Student by ID";
        cout << "\n5. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter Student ID: ";
                cin >> id;
                cin.ignore(); 
                cout << "Enter Student Name: ";
                getline(cin, name);
                sm.addStudent(id, name);
                break;
            case 2:
                sm.displayStudents();
                break;
            case 3:
                cout << "Enter Student ID to remove: ";
                cin >> id;
                sm.removeStudent(id);
                break;
            case 4:
                cout << "Enter Student ID to search: ";
                cin >> id;
                sm.searchStudent(id);
                break;
            case 5:
                cout << "Exiting program...\n";
                break;
            default:
                cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 5);

    return 0;
}