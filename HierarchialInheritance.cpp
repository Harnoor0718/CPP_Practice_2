#include <iostream>
#include <string>
using namespace std;

class Person {
public:
    string name;

    void setName(string n) {
        name = n;
    }

    void displayName() {
        cout << "Name: " << name << endl;
    }
};

class Student : public Person {
public:
    int rollno;

    void setStudent(string n, int r) {
        name = n;          // from Person
        rollno = r;
    }

    void displayStudent() {
        cout << "Student Name: " << name << endl;
        cout << "Roll No: " << rollno << endl;
    }
};

class Teacher : public Person {
public:
    string subject;
    double salary;

    void setTeacher(string n, string s, double sal) {
        name = n;         // from Person
        subject = s;
        salary = sal;
    }

    void displayTeacher() {
        cout << "Teacher Name: " << name << endl;
        cout << "Subject: " << subject << endl;
        cout << "Salary: " << salary << endl;
    }
};

int main() {
    Student s;
    s.setStudent("Peter Parker", 123);
    s.displayStudent();

    cout << endl;

    Teacher t;
    t.setTeacher("Stephen Strange", "Magic", 120000.75);
    t.displayTeacher();

    return 0;
}

