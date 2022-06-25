class Solution {
private:
    unordered_map<int, int> cnt;
public:
    int getKth(int lo, int hi, int k) {
        vector<pair<int, int>> res;
        
        for(int i = lo; i <= hi; i++){
            res.push_back(make_pair(getpower(i), i));
        }
        sort(res.begin(), res.end());
        return res[k-1].second;
    }
    
    
    int getpower(int k){
        if(cnt[k] or k == 1) return cnt[k];
        if(k%2 == 0) cnt[k] =  1 + getpower(k/2);
        else cnt[k] = 1 + getpower(3*k+1);
        return cnt[k];
    }
};