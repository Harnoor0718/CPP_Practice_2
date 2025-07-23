#include<iostream>
#include<string>
using namespace std;

bool isPalindrome(string str) {
    int st = 0, end = str.size() - 1;
    while(st <= end) {
        if(str[st] != str[end]) {
            return false;  // return false immediately on mismatch
        }
        st++;
        end--;
    }
    return true;  // if no mismatches found
}

int main() {
    cout << isPalindrome("Harnoor") << endl;   // Output: 0 (not a palindrome)
    cout << isPalindrome("madam") << endl;     // Output: 1 (is a palindrome)
    return 0;
}
