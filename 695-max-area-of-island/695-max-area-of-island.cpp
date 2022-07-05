class Solution {
public:
    int cnt;
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int res = 0;
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j] == 1) {
                    cnt = 0;
                    dfs(grid, i, j);
                    res = max(res, cnt);
                }
            }
        }
        return res;
    }
    
    void dfs(vector<vector<int>>& grid, int i, int j){
        if(i < 0 or i >= grid.size() or j < 0 or j >= grid[0].size() or grid[i][j] != 1) return;
        grid[i][j] = 2;
        cnt++;
        dfs(grid, i+1, j);
        dfs(grid, i, j+1);
        dfs(grid, i-1, j);
        dfs(grid, i, j-1);
    }
};