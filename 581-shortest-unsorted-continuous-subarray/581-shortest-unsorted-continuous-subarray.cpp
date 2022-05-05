class Solution {
public:
    int findUnsortedSubarray(vector<int>& A) {
        vector<int> B(A);
        sort(B.begin(), B.end());
        int i = 0, j = A.size() - 1;
        while(i < A.size() and A[i] == B[i]) i++;
        while(j > i and A[j] == B[j]) j--;
        return j - i + 1;
    }
};