class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        int i = 0, j = A.size() - 1;
        
        while(i < j){
            while(A[i] % 2 == 0 and i < j) i++;
            while(A[j] % 2 == 1 and i < j) j--;
            if(A[i] % 2 == 1 and A[j]%2 == 0) {
                swap(A[i], A[j]);
                i++;
                j--;
            }
        }
        return A;
    }
};