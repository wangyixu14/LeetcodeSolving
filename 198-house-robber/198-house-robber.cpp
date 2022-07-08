class Solution {
public:
    int rob(vector<int>& A) {
        if(A.size() == 1) return A[0];
        vector<int> dp(A.size(), 0);
        dp[0] = A[0];
        dp[1] = max(A[0], A[1]);
        
        for(int i = 2; i < A.size(); i++){
            dp[i] = max(dp[i-1], dp[i-2] + A[i]);
        }
        return dp.back();
    }
};