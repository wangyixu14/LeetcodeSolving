class Solution {
public:
    long long appealSum(string s) {
        vector<long long> dp(s.size(), 0); 
        long long prev[26] = {};
        long long res = 1;
        dp[0] = 1;
        prev[s[0] - 'a'] = 1;
        for(int i = 1; i < s.size(); i++){
            dp[i] = dp[i-1] + i + 1 - prev[s[i] - 'a'];
            res += dp[i];
            prev[s[i] - 'a'] = i + 1;
        }
        return res;
    }
};