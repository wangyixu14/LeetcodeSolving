class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(), boxTypes.end(), comp);
        int cnt = 0, res = 0;
        for(auto b: boxTypes){
            if(cnt + b[0] < truckSize) res += b[0]*b[1];
            else res += max(truckSize - cnt, 0) * b[1];
            cnt += b[0];
        }
        return res;
    }
    
    
    static bool comp(vector<int> & p1, vector<int> & p2){
        return p1[1] > p2[1];
    }
};