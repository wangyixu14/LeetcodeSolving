class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char, int> mp;
        
        for(int i = 0; i < s.size(); i++){
            mp[s[i]] = i;
        }
        vector<int> res;
        
        int i = 0;
        while(i < s.size()){
            int j = i, upper = mp[s[j]], pos = 0;
            while(j < upper){
                pos = max(pos, mp[s[j]]);
                if(pos > upper) upper = pos;
                j++;
            }
            res.push_back(j+1-i);
            i = j + 1;
        }

        return res;
    }
};