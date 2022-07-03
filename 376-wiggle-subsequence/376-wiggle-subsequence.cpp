class Solution {
public:
    int wiggleMaxLength(vector<int>& A) {
        if(A.size() == 1) return 1;
        if(A.size() == 2){
            if(A[0] != A[1]) return 2;
            else return 1;
        }
        vector<vector<int>> dp(A.size(), vector<int>(2, 0));
        
        dp[0][0] = 1;
        dp[0][1] = 1;
        
        if(A[1] > A[0]) dp[1][1] = 2;
        if(A[1] < A[0]) dp[1][0] = 2;

        for(int i = 2; i < A.size(); i++){
            for(int j = i -1; j >= 0; j--){
                if(A[j] < A[i]) dp[i][1] = max(dp[i][1], dp[j][0] + 1);
                if(A[j] > A[i]) dp[i][0] = max(dp[i][0], dp[j][1] + 1);
            }
        }
        
        int res = 0;
        for(auto d:dp){
            res = max(res, d[0]);
            res = max(res, d[1]);
        }
        
        return res;
    }
};