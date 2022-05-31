class Solution {
public:
    bool hasAllCodes(string s, int k) {
        if( k > s.size()) return false;
        unordered_set<string> mset;
        
        for(int i = 0; i <= s.size() - k;  i++){
            mset.insert(s.substr(i, k));
        }
        
        return mset.size() == pow(2, k);
    }
};