class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> pdict(26, 0), sdict(26, 0);
        vector<int> res;
        if(s.size() < p.size()) return res;
        
        for(auto e: p) pdict[e - 'a']++;
        for(int i = 0; i < p.size(); i++){
            sdict[s[i] - 'a']++;
        }
        
        if(check(sdict, pdict)) res.push_back(0);
        
        int j = p.size();
        while(j < s.size()){
            sdict[s[j] - 'a']++;
            sdict[s[j- p.size()] - 'a']--;
            if(check(sdict, pdict)) res.push_back(j - p.size() + 1);
            j++;
        }
        return res;
    }
    
    bool check(vector<int> sdict, vector<int> pdict){
        for(int i = 0; i < 26; i++){
            if(sdict[i] != pdict[i]) return false;
        }
        return true;
    }
};