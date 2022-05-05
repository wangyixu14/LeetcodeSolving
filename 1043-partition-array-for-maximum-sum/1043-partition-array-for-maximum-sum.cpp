class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& A, int k) {
        vector<int> dp(A.size(), 0);
        int maxv = 0;
        for(int i = 0; i < k; i++){
            maxv = max(maxv, A[i]);
            dp[i] = maxv*(i+1);
        }
        
        for(int i = k; i < A.size(); i++){
            int maxv = 0;
            for(int j = 0; j < k; j++){
                maxv = max(maxv, A[i-j]);
                dp[i] = max(dp[i], dp[i- j - 1] + maxv*(j+1));
            }
        }
        return dp.back();
    }
};