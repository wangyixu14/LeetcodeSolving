class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bots) {
        unordered_map<int, int> hash;
        for(int i = 0; i < tops.size(); i++){
            hash[tops[i]]++;
            hash[bots[i]]++;
        }
        int ele = 0, res1 = 0, res2 = 0;
        for(auto mp:hash){
            if(mp.second >= tops.size()) {
                ele = mp.first;
                break;
            }
        }
        
        
        if(!ele) return -1;
        
        for(int i = 0; i < tops.size(); i++){
            
            if(tops[i] == ele) continue;
            if(tops[i] != ele and bots[i] == ele) {
                // swap(tops[i], bots[i]);
                res1++;
            }
            else {return -1;}
        }
        
         for(int i = 0; i < tops.size(); i++){
            if(bots[i] == ele) continue;
            if(bots[i] != ele and tops[i] == ele) {
                // swap(tops[i], bots[i]);
                res2++;
            }
            else{return -1;}
        }       
        
        
        return min(res1, res2);
    }
};