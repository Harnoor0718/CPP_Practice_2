#include<iostream>
using namespace std;

int sumArray(int arr[], int sz) {
    int sum = 0;
    for(int i = 0; i < sz; i++) {
        sum = sum + arr[i];
    }
    return sum;
}
int productArray(int arr[],int sz){
    int product = 1;
    for(int i=0;i<sz;i++){
        product = product * arr[i];
    }
    return product;
}
int main(){
    int arr[]={3,4,5,6,7,9};
    int sz = sizeof(arr)/sizeof(int);
    cout<<sumArray(arr,sz)<<endl;
    cout<<productArray(arr,sz);
    return 0;
    }
