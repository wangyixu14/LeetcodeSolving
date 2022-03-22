class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& A) {
        vector<vector<int>> res;
        if(A.size() == 0) return res;
        sort(A.begin(), A.end());
        res.push_back(A[0]);
        int j = 0;
        for(int i = 1; i < A.size(); i++){
            // cout << A[i][0] << res[j][1] << endl;
            if(res[j][1]>=A[i][0]) res[j][1] = max(res[j][1], A[i][1]);
            else{
                j++;
                res.push_back(A[i]);
            }
        }
        return res;
    }
};