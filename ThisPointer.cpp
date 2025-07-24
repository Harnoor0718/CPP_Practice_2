#include <iostream>
#include <string>
using namespace std;

class Teacher {
public:
    // Constructor using 'this' pointer to avoid name conflicts
    Teacher(string name, string dept, string subject, int salary) {
        this->name = name;
        this->dept = dept;
        this->subject = subject;
        this->salary = salary;
    }

    string name;
    string subject;
    string dept;

    void setSalary(int s) {
        this->salary = s;
    }

    int getSalary() {
        return this->salary;
    }

    void getInfo() {
        cout << "Name: " << this->name << endl;
        cout << "Subject: " << this->subject << endl;
        cout << "Department: " << this->dept << endl;
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
