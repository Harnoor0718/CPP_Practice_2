#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main() {
    //stock prices
    vector<int> prices = {100, 80, 60, 70, 60, 60, 75, 85};

    //solution
    vector<int> ans(prices.size(), 0);
    stack<int> s;

    for(int i=0; i<prices.size(); i++){
        while(s.size() > 0 && prices[s.top()] <= prices[i]){
            s.pop();
        }

        if(s.empty()){
            ans[i] = i + 1;
        } else {
            ans[i] = i - s.top();
        }

        s.push(i);
    }

    //print ans vals
    for(int val : ans) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
