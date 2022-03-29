class Solution {
public:
    int findDuplicate(vector<int>& A) {
        sort(A.begin(), A.end());
        
        int lo = 0, hi = A.size() - 1;
        
        while(lo < hi) {
            int mid = (hi + lo) / 2;
            if(A[mid]  >= mid + 1) lo = mid + 1;
            else hi = mid;
        }
        return A[lo];
    }
};