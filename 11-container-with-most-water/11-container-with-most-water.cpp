class Solution {
public:
    int maxArea(vector<int>& H) {
        int i = 0, j = H.size()-1, maxarea = 0;
        while(i < j){
            maxarea = max(maxarea, min(H[i], H[j])*(j-i));
            H[i] < H[j]? i++:j--;
        }
        return maxarea;
    }
};