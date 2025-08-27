#include <iostream>
using namespace std;

bool isPrime(int n){
    if(n < 2) return false;
    if(n == 2 || n == 3) return true;
    if(n % 2 == 0) return false;
    for(int i=3;i<=n/2;i++){
        if(n%i == 0) return false;
    }
    return true;
}

int nextPrime(int n){
    int candidate = n+1;
    while(!isPrime(candidate)){
        candidate++;
    }
    return candidate;
}

int main() {
    int n;
    cin >> n;
    cout << nextPrime(n);
    return 0;
}

