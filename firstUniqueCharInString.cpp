class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char,int> m;
        queue<int> Q;

        for(int i=0;i<s.size();i++){
            if(m.find(s[i]) == m.end()){
                Q.push(i);
            }
            m[s[i]]++;

            while(Q.size()>0 && m[s[Q.front()]] > 1){
                Q.pop();
            }
        }
        return Q.empty() ? -1 : Q.front();
    }
};
