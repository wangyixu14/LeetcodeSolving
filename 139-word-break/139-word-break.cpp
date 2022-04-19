class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        if(s.size() == 0) return true;
        vector<bool> flag(s.size() + 1, false);
        flag[0] = true;
        
        unordered_map<string, int> mp;
        for(auto w:wordDict) mp[w]++;
        
        for(int i= 0; i < s.size() + 1; i++){
            for(int j = 0; j < i; j++){
                if(mp[s.substr(j, i-j)] && flag[j]) {
                    flag[i] = true;
                    break;
                }
            }
        }
        return flag.back();
    }
};