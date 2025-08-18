#include <iostream>
using namespace std;

class CircularQueue{
    int* arr;
    int currSize, cap;
    int f=0, r=-1;

public:
    CircularQueue(int size){
        cap = size;
        arr = new int[cap];
        currSize = 0;
        f = 0;
        r = -1;
    }

    void push(int data){
        if(currSize == cap){
            cout<<"CQ is FULL\n";
            return;
        }
        r = (r+1)%cap;
        arr[r] = data;
        currSize++;
    }

    void pop(){
        if(empty()){
            cout<<"CQ is EMPTY\n";
            return;
        }
        f = (f+1)%cap;
        currSize--;
    }

    int front(){
        if(empty()){
            cout<<"CQ is EMPTY\n";
            return -1;
        }
        return arr[f];
    }

    bool empty(){
        return currSize == 0;
    }

    void printArr(){
        if(empty()){
            cout<<"CQ is EMPTY\n";
            return;
        }
        cout<<"Queue: ";
        for(int i=0;i<currSize;i++){
            int idx = (f+i)%cap;
            cout<<arr[idx]<<" ";
        }
        cout<<"\n";
    }
};

int main(){
    CircularQueue cq(3);

    cq.push(1);
    cq.push(2);
    cq.push(3);
    cq.push(4);  // FULL

    cq.printArr();  // 1 2 3

    cq.pop();
    cq.printArr();  // 2 3

    cq.push(5);
    cq.printArr();  // 2 3 5

    return 0;
}
