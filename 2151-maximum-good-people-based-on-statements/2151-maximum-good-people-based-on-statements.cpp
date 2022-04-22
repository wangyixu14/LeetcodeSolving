class Solution {
private:
    int n = 0;
    int res = 0;

public:
    int maximumGood(vector<vector<int>>& S) {
        n = S.size();
        string path = "";
        dfs(S, path, 0, 0);
        return res;
    }
    
    void dfs(vector<vector<int>> & S, string& path, int i, int cnt){
        // cout << cnt << endl;
        if(i == n){
            if(valid(path, S)) res = max(res, cnt);
            return;
        }
        path.push_back('1');
        dfs(S, path, i+1, cnt+1);
        path.back() = '0';
        dfs(S, path, i+1, cnt);
        path.pop_back();
    }
    
    bool valid(string& path, vector<vector<int>> & S){
        for(int i = 0; i < n; i++){
            if(path[i] == '1'){
                for(int j = 0; j < n; j++){
                    if(S[i][j] != 2 and S[i][j] != path[j] - '0') return false;
                }
            }
        }
        return true;
    }
};