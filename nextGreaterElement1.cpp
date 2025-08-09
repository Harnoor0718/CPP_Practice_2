
#include <vector>
#include <stack>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> m; // maps value -> next greater
        stack<int> s;

        // Build the map for nums2
        for (int i = nums2.size() - 1; i >= 0; i--) {
            while (!s.empty() && s.top() <= nums2[i]) {
                s.pop();
            }
            if (s.empty()) {
                m[nums2[i]] = -1;
            } else {
                m[nums2[i]] = s.top();
            }
            s.push(nums2[i]);
        }

        // Prepare answer for nums1 based on map
        vector<int> ans;
        for (int num : nums1) {
            ans.push_back(m[num]);
        }

        return ans;
    }
};
