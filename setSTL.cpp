#include <iostream>
#include <set>

using namespace std;

int main() {
    set<int> s;

    s.insert(1);
    s.insert(2);
    s.insert(3);
    s.insert(4);
    s.insert(5);

    for(auto val : s) {
        cout << val << " ";
    }
    cout<<"lower bound"<<" "<<lower_bound(4)<<endl; //4
    cout<<"upper bound"<<" "<<upper_bound(4)<<endl; //5
    cout << endl;

    return 0;
}
