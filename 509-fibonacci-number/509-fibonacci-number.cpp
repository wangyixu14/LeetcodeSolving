class Solution {
public:
    int fib(int n) {
        if(n==0) return 0;
        int lo = 1, hi = 1, i = 1;
        while(i < n-1){
            int f = lo + hi;
            lo = hi;
            hi = f;
            i++;
        }
        return hi;
    }
};