#include <iostream>
#include <string>
using namespace std;

class Teacher {
public:
    // Parameterized Constructor
    Teacher(string n, string d, string s, int sal) {
        name = n;
        dept = d;
        subject = s;
        salary = sal;
    }

    // Copy Constructor
    Teacher(const Teacher &t) { //Pass by Reference
        name = t.name;
        dept = t.dept;
        subject = t.subject;
        salary = t.salary;
        cout << "Copy constructor called!" << endl;
    }

    void getInfo() {
        cout << "Name: " << name << endl;
        cout << "Subject: " << subject << endl;
        cout << "Department: " << dept << endl;
        cout << "Salary: " << salary << endl;
    }

private:
    string name;
    string subject;
    string dept;
    int salary;
};

int main() {
    Teacher t1("Shradha", "CS", "C++", 25000);

    // Using copy constructor
    Teacher t2 = t1;

    cout << "Original Teacher (t1):" << endl;
    t1.getInfo();

    cout << "\nCopied Teacher (t2):" << endl;
    t2.getInfo();

    return 0;
}
