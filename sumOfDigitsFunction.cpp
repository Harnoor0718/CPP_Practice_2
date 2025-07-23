#include<iostream>
using namespace std;
int sumDigits(int n){
   int sum = 0;
   while(n>0){
    int r = n%10;
    n = n/10;
    sum += r;

   }
    return sum;
}
int main(){
    cout<<sumDigits(145);
    return 0;
    }
