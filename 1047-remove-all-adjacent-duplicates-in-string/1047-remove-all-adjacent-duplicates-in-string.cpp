class Solution {
public:
    string removeDuplicates(string s) {
        string res = "";
        stack<char> mystack;
        for(auto c : s){
            if(!mystack.empty() and mystack.top() == c) mystack.pop();
            else mystack.push(c);
        }
        
        while(!mystack.empty()){
            res = mystack.top() + res;
            mystack.pop();
        }
        return res;
    }
};