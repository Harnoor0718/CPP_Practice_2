#include<iostream>
#include<vector>
using namespace std;
int main(){
    vector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    vec.emplace_back(6);
    vec.pop_back();


    cout<<vec.size()<<endl;
    cout<<vec.capacity()<<endl;
    cout<<vec.front()<<endl;
    cout<<vec.back()<<endl;

    for(int val : vec){
        cout<<val<<" ";
    }
    cout<<endl;

    return 0;
    }
