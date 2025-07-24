#include <iostream>
using namespace std;

class Student {
public:
    string name;
    double* cgpaPtr;

    // Constructor
    Student(string n, double cgpa) {
        name = n;
        cgpaPtr = new double;
        *cgpaPtr = cgpa;
    }

    // Shallow Copy Constructor
    Student(const Student &obj) {
        name = obj.name;
        cgpaPtr = obj.cgpaPtr;
        cout << "Shallow copy constructor called!" << endl;
    }

    void getInfo() {
        cout << "Name: " << name << endl;
        cout << "CGPA: " << *cgpaPtr << endl;
    }

    ~Student() {
        delete cgpaPtr;
    }
};

int main() {
    Student s1("Rahul", 8.9);
    Student s2 = s1;  // Shallow copy

    cout << "\nOriginal Student (s1):" << endl;
    s1.getInfo();

    // Modify s2's CGPA
    *(s2.cgpaPtr) = 9.2;

    cout << "\nAfter modifying s2's CGPA (shallow copy affects s1 too):" << endl;
    cout << "s1 info:" << endl;
    s1.getInfo();
    cout << "s2 info:" << endl;
    s2.getInfo();

    return 0;
}
