#include <iostream>
#include <string>
using namespace std;

class Teacher {
public:
    //non parameterised
    Teacher(){
      dept = "Computer Science";
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

private:
    int salary;
};

int main() {
    Teacher t1;
    Teacher t2; //automatically constructor called
    t1.name = "Shradha";
    t1.subject = "C++";

    t1.setSalary(25000);

    cout << t1.name << endl;
    cout << t1.dept << endl;

    return 0;
}
