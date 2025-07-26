#include <iostream>
#include <string>
using namespace std;

void fun() {
    static int x = 0; //if static is not used x will remain zero
    cout<<"x : "<<x<<endl;
    x++;
}

int main() {
    fun();
    fun();
    fun();
    return 0;
}

