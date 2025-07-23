#include<iostream>
#include<string>
using namespace std;
class Teacher{
private:
    double salary;

public :
    //Properties or Attributes
    string name;
    string dept;
    string subject;


    //methods or member functions
    void changeDept(string newDept){
        dept = newDept ;
    }
    //setter
    void setSalary(int s){
        salary = s;
        }
     //getter
    double getSalary(){
        return salary;
        }
    };

class Account {
private:
    double balance;
    string password; //data hidden

public:
    string accountId;
    string username;

    };


int main(){
    Teacher t1;
    t1.name = "Shradha";
    t1.dept = "CSE";
    t1.subject = "CPP";
    t1.setSalary(25000)
    cout<<t1.name<<endl;
    cout<<t1.getSalary()<<endl;
    return 0;
    }
