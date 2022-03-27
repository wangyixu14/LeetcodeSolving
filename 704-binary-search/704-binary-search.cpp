class Solution {
public:
    int search(vector<int>& A, int target) {
        int lo = 0, hi = A.size()-1;
        
        while(lo < hi) {
            int mid = (lo + hi) / 2;
            if(A[mid] < target) lo = mid + 1;
            else hi = mid;
        }
        // cout << lo << hi << endl;
        return target == A[lo]? lo:-1;
    }
};