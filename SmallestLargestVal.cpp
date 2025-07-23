#include<iostream>
using namespace std;

int main() {
    int nums[] = {2,4,5,6,7};  // Correct declaration of an array
    int size = sizeof(nums) / sizeof(int); // Or sizeof(nums[0])

    int smallest = INT_MAX;
    for(int i=0;i<size;i++){
        if(nums[i]<smallest){
            smallest=nums[i];
        }
    }
    cout<<smallest;
    return 0;
}
