class Solution {
public:
    bool binary(vector<int>& A, int target, int lo, int hi){
        int l = lo, r = hi;
        while(l < r){
            int mid = (l + r) / 2;
            if(A[mid] < target) l = mid + 1;
            else r = mid;
        }
        return l == hi? false : A[l] == target;
    }
    bool search(vector<int>& A, int target) {
        if(A.size() == 1) return target == A[0];
        int lo = 0;
        for(int i = 1; i < A.size(); i++){
            if(A[i] < A[i-1]) {
                lo = i;
                break;
            }
        }
        cout << lo << endl;
        return binary(A, target, 0, lo) or binary(A, target, lo, A.size());
    }
};