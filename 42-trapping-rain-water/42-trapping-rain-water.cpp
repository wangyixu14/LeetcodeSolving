class Solution {
public:
    int trap(vector<int>& H) {
        int i = 0, j = H.size() - 1, maxleft = 0, maxright = 0, res = 0;
        while(i < j){
            if(H[i] > H[j]){
                if(H[j] > maxright) maxright = H[j];
                else res += (maxright - H[j]);
                j--;
            }
            
            else{
                if(H[i] > maxleft) maxleft = H[i];
                else res += (maxleft - H[i]);
                i++;
            }
        }
        return res;
    }
};