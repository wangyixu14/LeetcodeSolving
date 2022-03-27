class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& A, vector<int>& B) {
        unordered_map<int, int> mA, mB;
        for(int a: A) mA[a]++;
        for(int b: B) mB[b]++;
        
        vector<vector<int>> res(2, vector<int> ());
        
        for(auto a: mA){
            if(!mB[a.first]) res[0].push_back(a.first);
        }
        
        for(auto b: mB){
            if(!mA[b.first]) res[1].push_back(b.first);
        }
        return res;
    }
};