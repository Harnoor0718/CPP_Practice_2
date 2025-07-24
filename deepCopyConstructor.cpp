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

    // Deep Copy Constructor
    Student(const Student &obj) {
        name = obj.name;
        cgpaPtr = new double;             // Allocate new memory
        *cgpaPtr = *(obj.cgpaPtr);        // Copy the value
        cout << "Deep copy constructor called!" << endl;
    }

    // Display function
    void getInfo() {
        cout << "Name: " << name << endl;
        cout << "CGPA: " << *cgpaPtr << endl;
    }

    // Destructor
    ~Student() {
        delete cgpaPtr;
    }
};

int main() {
    Student s1("Rahul", 8.9);
    Student s2 = s1;  // Calls deep copy constructor

    cout << "\nOriginal Student (s1):" << endl;
    s1.getInfo();

    // Change s2's CGPA
    *(s2.cgpaPtr) = 9.5;

    cout << "\nAfter modifying s2's CGPA:" << endl;
    cout << "s1 info:" << endl;
    s1.getInfo();  // Should still show 8.9
    cout << "s2 info:" << endl;
    s2.getInfo();  // Should show 9.5

    return 0;
}

