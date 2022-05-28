class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char, int>> ms;
        string res = "";
        for(auto c : s){
            if(!ms.empty() and c == ms.top().first and ms.top().second == k -1) ms.pop();
            else if(!ms.empty() and c == ms.top().first) ms.top().second++;
            else{
                pair<char, int> countpair = make_pair(c, 1);
                ms.push(countpair);
            }
        }
        
        while(!ms.empty()){
            pair<char, int> p = ms.top();
            ms.pop();
            res.insert(0, p.second, p.first);
        }
        return res;
    }
};