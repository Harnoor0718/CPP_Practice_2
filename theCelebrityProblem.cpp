#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int getCelebrity(vector<vector<int>> arr) {
    int n = arr.size(); // FIX: define n
    stack<int> s;
    for(int i = 0; i < n; i++){
        s.push(i);
    }
    while(s.size() > 1){
        int i = s.top();
        s.pop();

        int j = s.top();
        s.pop();

        if(arr[i][j] == 0){
            s.push(i);
        } else {
            s.push(j);
        }
    }
    int celeb = s.top();
    for(int i = 0; i < n; i++){
        if(i != celeb && (arr[i][celeb] == 0 || arr[celeb][i] == 1)){ // FIX: proper check
            return -1; // No celebrity
        }
    }
    return celeb;
}

int main() {
    vector<vector<int>> arr = { {0,1,0},
                                {0,0,0},
                                {0,1,0} };

    int ans = getCelebrity(arr);

    cout << "celebrity is : " << ans << endl;

    return 0;
}
