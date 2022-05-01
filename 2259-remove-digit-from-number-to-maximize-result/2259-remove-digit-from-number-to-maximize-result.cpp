class Solution {
public:
    string removeDigit(string A, char digit) {
        vector<string> res;
        for(int i = 0; i < A.size(); i++){
            if(A[i] == digit){
                string tem = A.substr(0, i);
                tem += A.substr(i + 1, A.size() - i );
                res.push_back(tem);
            }
        }
        sort(res.begin(), res.end());
        return res.back();
    }
};