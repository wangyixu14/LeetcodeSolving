class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        // int dp[days.back()+31];
        vector<int> dp(days.back()+31);
        dp[0] = 0;
        int j = 0;
        for(int i = 31; i < dp.size(); i++){
            if(i-30 == days[j]){
                dp[i] = min(dp[i-1] + costs[0], min(dp[i-7] + costs[1], dp[i-30] + costs[2]));
                j++;
            }
            else dp[i] = dp[i-1];
            // cout << i << dp[i] << endl;
        }
        return dp.back();
    }
};