#include <iostream>
#include <string>
using namespace std;

class Parent {
public :
    void getInfo(){
        cout<<"parent class\n";
    }
};

class Child : public Parent{
public:
    void getInfo(){
        cout<<"child class\n";
        }
    };

int main() {
    Parent p1;
    p1.getInfo();
    return 0;
}

