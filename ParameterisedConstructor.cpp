#include <iostream>
#include <string>
using namespace std;

class Teacher {
public:
    // Constructor with int salary to match the private member
    Teacher(string n, string d, string s, int sal) {
        name = n;
        dept = d;
        subject = s;
        salary = sal;
    }

    string name;
    string subject;
    string dept;

    void setSalary(int s) {
        salary = s;
    }

    int getSalary() {
        return salary;
    }

    void getInfo() {
        cout << "Name: " << name << endl;
        cout << "Subject: " << subject << endl;
        cout << "Department: " << dept << endl;
    }

private:
    int salary;
};

int main() {
    Teacher t1("Shradha", "CS", "CPP", 25000);

    // Access info
    t1.getInfo();
    cout << "Salary: " << t1.getSalary() << endl;

    return 0;
}
