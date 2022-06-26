class Solution {
public:
    bool checkIfCanBreak(string s1, string s2) {
        sort(s1.begin(), s1.end());
        sort(s2.begin(), s2.end());
        
        int lo = INT_MAX,  hi = -INT_MAX;
        
        for(int i = 0; i < s1.size(); i++){
            lo = min(s1[i] - s2[i], lo);
            hi = max(s1[i] - s2[i], hi);
        }
        
        return lo*hi >= 0;
    }
};