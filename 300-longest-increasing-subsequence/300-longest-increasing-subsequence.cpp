class Solution {
public:
    int lengthOfLIS(vector<int>& A) {
        vector<int> res;
        
        for(int a : A){
            if(res.empty() or a > res.back()) res.push_back(a);
            else{
                auto it = lower_bound(res.begin(), res.end(), a);
                *it = a;
            }
        }
        return res.size();
    }
};