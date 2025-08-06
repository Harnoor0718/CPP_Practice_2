#include<iostream>
#include<vector>
#include<list>
using namespace std;

class Stack{
    list<int> ll;

public:
    void push(int val){
        ll.push_front(val);
        }

    void pop(){
       ll.pop_front();
        }

    int top(){
        return ll.front();
        }

    bool empty(){
        return ll.size() == 0;
    }
    };

int main(){
    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);

    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
    cout<<endl;
    return 0;
}
