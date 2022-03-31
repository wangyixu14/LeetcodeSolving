class Solution {
public:
    int splitArray(vector<int>& A, int m) {
        int lo = 0, hi = 0;
        
        for(auto a:A) {
            lo = max(lo, a);
            hi += a;
        }
        
        while(lo <= hi) {
            int mid = (lo + hi) / 2;
            if(!valid(A, m, mid)) lo = mid + 1;
            else hi = mid - 1;
        }
        
        return lo;
    }
    
    bool valid(vector<int>& A, int m, int target){
        int sum = 0, cnt = 1;
        for(auto a: A){
            sum += a;
            if(sum > target){
                sum = a;
                cnt++;
            }
            if(cnt > m) return false;
        }
        return true;
    }
};