class Solution {
public:
    int jump(vector<int>& A) {
        int res = 0, maxnext = 0, levelend = 0;
        
        for(int i = 0; i < A.size()-1; i++){
            maxnext = max(maxnext, A[i] + i);
            
            if(i == levelend){
                res++;
                levelend = maxnext;
            }
        }
        return res;
    }
};