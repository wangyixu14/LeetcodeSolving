class Solution {
public:
    int lengthOfLIS(vector<int>& A) {
        vector<int> dp(A.size(), 1);
        // int dp_max = 1;
        
        for(int i = 1; i < A.size(); i++){
            for(int j = i-1; j > -1; j--){
                if(A[j] < A[i]) {
                    dp[i] = max(dp[j] + 1, dp[i]); 
                }
            }
        }
        int dp_max = 0;
        for(auto d:dp)
            dp_max = max(dp_max, d);
        return dp_max;
    }
};