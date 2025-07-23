#include<iostream>
#include<climits>
using namespace std;

void swapMaxMin(int arr[], int sz, int &minValue, int &maxValue) {
    int smallest = INT_MAX;
    int largest = INT_MIN;
    int minIndex = -1;
    int maxIndex = -1;

    for(int i = 0; i < sz; i++) {
        if(arr[i] < smallest) {
            smallest = arr[i];
            minIndex = i;
        }
    }

    for(int i = 0; i < sz; i++) {
        if(arr[i] > largest) {
            largest = arr[i];
            maxIndex = i;
        }
    }

    if(minIndex != -1 && maxIndex != -1) {
        int temp = arr[minIndex];
        arr[minIndex] = arr[maxIndex];
        arr[maxIndex] = temp;
    }

    minValue = INT_MAX;
    maxValue = INT_MIN;
    for(int i = 0; i < sz; i++) {
        if(arr[i] < minValue) minValue = arr[i];
        if(arr[i] > maxValue) maxValue = arr[i];
    }
}

int main() {
    int arr[] = {23, 45, 67, 89};
    int sz = sizeof(arr) / sizeof(int);
    int minValue, maxValue;

    swapMaxMin(arr, sz, minValue, maxValue);

    cout << "Array after swapping min and max: ";
    for(int i = 0; i < sz; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    cout << "New min value: " << minValue << endl;
    cout << "New max value: " << maxValue << endl;

    return 0;
}
