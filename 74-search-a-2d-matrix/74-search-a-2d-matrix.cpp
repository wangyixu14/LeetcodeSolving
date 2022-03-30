class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int low = 0, high = matrix.size()*matrix[0].size()-1;
        int row, col, mid;
        while(low < high){
            mid = (low + high) >> 1;
            row = (mid) / matrix[0].size();
            col = (mid) % matrix[0].size();
            cout << mid << row << col << endl;
            if(matrix[row][col] < target){
                low = mid + 1;
            }
            else{
                high = mid;
            }
        }
        return matrix[(low) / matrix[0].size()][(low) % matrix[0].size()] == target;
    }
};
