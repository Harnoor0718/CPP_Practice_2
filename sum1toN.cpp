#include<iostream>
using namespace std;

int main(){
    int n;
    cout << "Enter number: ";
    cin >> n;

    int sum = 0;
    for(int i = 0; i < n; i++){
        sum = sum+i ;
    }

    cout << "Sum: " << sum << endl;
    return 0;
}
