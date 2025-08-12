class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> left(n,0);  // index of smaller to the left
        vector<int> right(n,0); // index of smaller to the right
        stack<int> s;

        // Right smaller
        for(int i=n-1; i>=0; i--){
            while(!s.empty() && heights[s.top()] >= heights[i]){
                s.pop();
            }
            right[i] = s.empty() ? n : s.top();
            s.push(i);
        }

        // clear stack before next use
        while(!s.empty()) s.pop();

        // Left smaller
        for(int i=0; i<n; i++){
            while(!s.empty() && heights[s.top()] >= heights[i]){
                s.pop();
            }
            left[i] = s.empty() ? -1 : s.top();
            s.push(i);
        }

        int ans = 0;
        for(int i=0; i<n; i++){
            int width = right[i] - left[i] - 1;
            int currArea = heights[i] * width;
            ans = max(ans, currArea);
        }
        return ans;
    }
};

