class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        int dp[m+1][n+1];
        memset(dp, 0, sizeof(dp));
        for(string s: strs){
            int ones = count(s.begin(), s.end(), '1');
            int zeros = s.size() - ones;
            for(int i = m; i >= zeros; i--){
                for(int j = n; j >= ones; j--){
                    dp[i][j] = max(dp[i][j], dp[i-zeros][j-ones] + 1);
                }
            }
        }
        return dp[m][n];
    }
};