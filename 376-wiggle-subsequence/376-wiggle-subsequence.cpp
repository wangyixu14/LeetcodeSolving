class Solution {
public:
    int wiggleMaxLength(vector<int>& A) {
        vector<int> up(A.size(), 0);
        vector<int> down(A.size(), 0);
        up[0] = 1;
        down[0] = 1;
        
        for(int i = 1; i < A.size(); i++){
            if(A[i] > A[i-1]){
                up[i] = down[i-1] + 1;
                down[i] = down[i-1];
            }
            else if(A[i] < A[i-1]){
                up[i] = up[i-1];
                down[i] = up[i-1] + 1;
            }
            else{
                up[i] = up[i-1];
                down[i] = down[i-1];                
            }
        }
        return max(up.back(), down.back());
    }
};