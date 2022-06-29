class Solution {
public:
    int minDeletions(string s) {
        unordered_set<int> record;
        vector<int> dict(26, 0);
        for(auto c:s) dict[c-'a']++;
        sort(dict.begin(), dict.end(), greater<int>());
        int res = 0;
        for(auto d: dict){
            // if(d>0)
            // {
               while(d >0 and record.count(d)){
                d--;
                res++;
                }
                record.insert(d); 
           // }
        }
        
        return res;
    }
};