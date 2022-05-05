class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        map<int, int> mp;
        int res = 0;
        for(auto a : nums) {
            mp[a]++;
        }
        for(auto it=mp.begin(); it!=mp.end(); ++it){
            if(k - it->first == it->first) {
                res += (it->second / 2);
            }
            else{
                int num = mp[k - it->first];
                res += min(it->second, num);
                mp[it->first] = 0;
                mp[k - it->first] = 0;
            }
        }
        return res;
    }
};