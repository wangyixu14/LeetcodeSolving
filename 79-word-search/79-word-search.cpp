class Solution {
public:
    bool dfs(vector<vector<char>> & board, string s, int i, int j){
        if(s.size() == 0) return true;
        if(i < 0 or i >= board.size() or j < 0 or j >= board[0].size() or board[i][j] != s[0]) return false;
        
        char tem = board[i][j];
        board[i][j] = '#';
        s = s.substr(1);
        bool res = dfs(board, s, i+1, j) or dfs(board, s, i, j+1) or dfs(board, s, i-1, j) or dfs(board, s, i, j-1);
        board[i][j] = tem;
        return res;
    }
    bool exist(vector<vector<char>>& board, string word) {
        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[0].size(); j++){
                if(dfs(board, word, i, j)) return true;
            }
        }
        return false;
    }
};