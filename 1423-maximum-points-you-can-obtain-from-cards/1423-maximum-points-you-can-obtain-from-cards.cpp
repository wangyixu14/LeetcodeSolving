class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        vector<int> circle(2*k, 0);
        int n = cardPoints.size(), sum = 0, res = 0;
        for(int i = 0; i < circle.size(); i++){
            circle[i] = cardPoints[(n-k+i)%n];
            sum += circle[i];
            
            if(i>=k) sum -= circle[i-k];
            res = max(sum, res);
        }
        return res;
    }
};