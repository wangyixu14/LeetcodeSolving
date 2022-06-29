class Solution {
public:
    static bool comp(vector<int> p1, vector<int> p2){
        if(p1[0] != p2[0]) return p1[0] < p2[0];
        else return p1[1] > p2[1];
    }
    
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        vector<vector<int>> res(people.size(), vector<int>(2, -1));
        sort(people.begin(), people.end(), comp);
        
        for(auto p : people){
            int cnt = 0, j = 0;
            while(cnt < p[1]){
                if(res[j][0] == -1){
                    cnt++;
                }
                j++;
            }
            while(res[j][0] != -1) j++;
            res[j] = p;
        }
        
        return res;
    }
};