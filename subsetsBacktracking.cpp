#include <iostream>
#include <vector>
using namespace std;

void printSubsets(vector<int> &arr, vector<int> &res, int i) {
    if(i == arr.size()) {
        for(int val : res) {
            cout << val << " ";
        }
        cout << endl;
        return;
    }
    // include
    res.push_back(arr[i]);
    printSubsets(arr, res, i + 1);

    // exclude
    res.pop_back(); // backtrack
    printSubsets(arr, res, i + 1);
}

int main() {
    vector<int> arr = {1, 2, 3};
    vector<int> ans;
    printSubsets(arr, ans, 0);
    return 0;
}
