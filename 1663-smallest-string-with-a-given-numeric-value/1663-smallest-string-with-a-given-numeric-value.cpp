class Solution {
public:
    string getSmallestString(int n, int k) {
        string res(n, ' ');;
        while(n > 0){
            int maxv = min(26, k - n + 1);
            char ele = 'a' + maxv - 1;
            res[n-1] = ele;
            k -= maxv;
            n--;
        }
        return res;
    }
};