class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        map<int, int> mp;
        int res = 0;
        for(auto a : nums) {
            mp[a]++;
        }
        for(auto m=mp.begin(); m!=mp.end(); ++m){
            // cout << m->first << " "  << m->second << endl;
            if(k - m->first == m->first) {
                res += (m->second / 2);
                // cout << m.first << endl;
            }
            else{
                int num = mp[k - m->first];
                res += min(m->second, num);
                mp[m->first] = 0;
                mp[k - m->first] = 0;
            }
        }
        return res;
    }
};