#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

int main() {
    unordered_map<string, int> m;

    m.emplace("tv", 100);
    m.emplace("laptop", 100);
    m.emplace("watch", 100);
    m.emplace("tablets", 100);

    for(auto p : m) {
        cout << p.first << " " << p.second << endl;
    }

    return 0;
}
