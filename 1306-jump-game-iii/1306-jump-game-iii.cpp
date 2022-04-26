class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        vector<bool> vis(arr.size());
        return dfs(arr, start, vis);
    }
    
    bool dfs(vector<int>& arr, int i, vector<bool>& vis){
        if( i < 0 or i >= arr.size() or vis[i]) return false;
        if(arr[i] == 0) return true;
        vis[i] = true;   
        return dfs(arr, i - arr[i], vis) or dfs(arr, i+arr[i], vis);
    }
};