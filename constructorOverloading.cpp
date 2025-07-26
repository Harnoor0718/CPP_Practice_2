#include <iostream>
#include <string>
using namespace std;

class Student {
public:
    string name;

    Student(){
    cout<<"non-parameterised constructor"<<endl;
    }

    Student(string name){
    this->name = name;
    cout<<"parameterized constructor"<<endl;
    }
};

int main() {
    Student s1();
    Student("Shradha");
    return 0;
}

