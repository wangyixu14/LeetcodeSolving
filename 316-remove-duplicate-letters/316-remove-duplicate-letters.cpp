class Solution {
public:
    string removeDuplicateLetters(string s) {
        string res = "";
        vector<int> pos(26);
        vector<bool> visited(26);
        
        for(int i = 0; i < s.size(); i++){
            pos[s[i]-'a'] = i;
        }
        
        for(int i = 0; i < s.size(); i++){
            if(visited[s[i]-'a']) continue;
            while(!res.empty() and res.back() > s[i] and pos[res.back()-'a'] > i){
                visited[res.back() -'a'] = false;
                res.pop_back();
            }
            res.push_back(s[i]);
            visited[s[i]-'a'] = true;
        }
        return res;
    }
};