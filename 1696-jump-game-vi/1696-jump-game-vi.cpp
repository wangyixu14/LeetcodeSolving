class Solution {
public:
    int maxResult(vector<int>& A, int k) {
        vector<int> dp(A.size(), INT_MIN);
        dp[0] = A[0];
        multiset<int> pq;
        pq.insert(A[0]);        
        for(int i = 1; i < A.size(); i++){
            if(i > k) pq.erase(pq.find(dp[i-k-1]));
            dp[i] = *rbegin(pq) + A[i];
            pq.insert(dp[i]);
        }
        return dp.back();
    }
};