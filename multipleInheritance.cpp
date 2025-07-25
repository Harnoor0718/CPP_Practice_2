
#include <iostream>
using namespace std;

class Person {
public:
    string name;
    int age;
};

class Student {
public:
    int rollno;
    string course;
};

class CollegeStudent : public Person, public Student {
public:
    void display() {
        cout << "Name   : " << name << endl;
        cout << "Age    : " << age << endl;
        cout << "RollNo : " << rollno << endl;
        cout << "Course : " << course << endl;
    }
};

int main() {
    CollegeStudent cs;
    cs.name = "Harnoor";
    cs.age = 20;
    cs.rollno = 123;
    cs.course = "B.Tech CSE";

    cs.display();

    return 0;
}
