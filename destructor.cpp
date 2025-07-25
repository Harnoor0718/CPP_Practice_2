#include <iostream>
using namespace std;

class Student {
public:
    string name;

    // Constructor
    Student(string studentName) {
        name = studentName;
        cout << "Constructor called for " << name << endl;
    }

    // Destructor
    ~Student() {
        cout << "Destructor called for " << name << endl;
    }
};

int main() {
    Student s1("Harnoor");

    {
        Student s2("Kaur");  // Local scope
    }  // Destructor for s2 called here automatically

    cout << "End of main function." << endl;

    return 0;
}

