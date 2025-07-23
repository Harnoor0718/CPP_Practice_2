#include <iostream>
using namespace std;
int uniqueVals(int arr[], int sz) {
    if(sz == 0) return 0;
    int count = 1;
    cout << arr[0] << " ";
    for (int i = 1; i < sz; i++) {
        if (arr[i] != arr[i - 1]) {
            cout << arr[i] << " ";
            count++;
        }
    }
    cout << endl;
    return count;
}int main() {
    int arr[] = {1, 1, 2, 3, 3, 4, 5, 5};
    int sz = sizeof(arr) / sizeof(arr[0]);
    cout << "Number of unique values: " << uniqueVals(arr, sz) << endl;
    return 0;
}
