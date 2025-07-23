
#include<iostream>
using namespace std;

int main(){
    int n;
    cout << "Enter number: ";
    cin >> n;

    int oddSum = 0;
    for(int i = 0; i < n; i++){
            if(i%2 != 0){
        oddSum = oddSum+i ;
            }
    }

    cout << "Sum: " << oddSum << endl;
    return 0;
}
