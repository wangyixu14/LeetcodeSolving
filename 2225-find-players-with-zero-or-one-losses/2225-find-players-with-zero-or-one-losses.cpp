class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        unordered_map<int, int> lose;
        unordered_set<int> player;
        
        for(auto m: matches){
            player.insert(m[0]);
            player.insert(m[1]);
            lose[m[1]]++;
        }
        vector<vector<int>> res(2);
        for(auto p: player){
            if(lose[p] == 0) res[0].push_back(p);
            if(lose[p] == 1) res[1].push_back(p);
        }
        
        sort(res[0].begin(), res[0].end());
        sort(res[1].begin(), res[1].end());
        return res;
    }
};