#include <iostream>
#include <algorithm>  // Required for sort()
using namespace std;

int main() {
    int arr[5] = {3, 5, 4, 1, 6};
    int n = sizeof(arr)/sizeof(arr[0]);  // Calculate array size

    sort(arr, arr + n);  // Sort the array

    for(int val : arr) {
        cout << val << " ";  // Print sorted values
    }

    return 0;
}
