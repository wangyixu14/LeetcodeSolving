class Solution {
public:
    bool check(unordered_map<char, int> mp1, unordered_map<char, int> mp2){
        for(auto m: mp1){
            if(mp2[m.first] > 0) return false;
        }
        
        return true;
    } 
    
    int maxProduct(vector<string>& words) {
        // vector<unordered_map<char, int>> mp(words.size());
        vector<int> mp(words.size());
        unsigned long res = 0;
        for(int i = 0; i < mp.size(); i++){
            for(auto c: words[i]){
                mp[i] |= 1 << (c - 'a');
            }
            for(int j = 0; j < i; j++){
                if(!(mp[i] & mp[j])) res = max(res, words[i].size() * words[j].size());
            }
        }
        return res;
    }
};