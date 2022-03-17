class Solution {
public:
    bool canBeValid(string s, string locked) {
        if(s.size()%2) return false;
        int open = 0, close = 0, zero = 0;
        for(int i = 0; i < s.size(); i++){
            if (locked[i] == '0') zero++;
            else if(s[i] == '(') open++;
            else if(s[i] == ')') close++;
            if(close-open > zero) return false;
        }
        open = 0, close = 0, zero = 0;
        for(int i = s.size() - 1; i > -1; i--){
            if (locked[i] == '0') zero++;
            else if(s[i] == '(') open++;
            else if(s[i] == ')') close++;
            if(open-close > zero) return false;           
        }
        return true;
    }
};