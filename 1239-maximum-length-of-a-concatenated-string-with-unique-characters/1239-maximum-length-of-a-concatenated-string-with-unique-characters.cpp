class Solution {
private:
    int res = 0;
public:
    int maxLength(vector<string>& arr) {    
        string path ="";
        
        backtrack(arr,  0, path);
        return res;
    }
    
    bool check(string word) {
        set<char> st;
        for (auto ele : word) {
            if (st.find(ele) != st.end()) return false;
            st.insert(ele);
        }
        return true;
    }
    
    void backtrack(vector<string>& arr, int i, string &path){
        if(!check(path)) return;
        
        if(path.size() > res) res = path.size();
        
        for(int k = i; k < arr.size(); k++){
                path += arr[k];
                backtrack(arr, k+1, path);
                path = path.substr(0, path.size()-arr[k].size());
            }
        }
};

// class Solution {
//     int len{0};
// public:
//     int maxLength(vector<string>& arr) {
//         checkLen("", arr, 0);
//         return len;
//     }
    
//     void checkLen(string str, vector<string> &arr, int itr) {
//         if (!isUnique(str)) return;
//         if (str.size() > len) len = str.size();
//         for (int i = itr; i < arr.size(); i++)
//             checkLen(str+arr[i], arr, i+1);
//     }
    
//     bool isUnique(string word) {
//         set<char> st;
//         for (auto ele : word) {
//             if (st.find(ele) != st.end()) return false;
//             st.insert(ele);
//         }
//         return true;
//     }
// };