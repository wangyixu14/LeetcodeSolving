class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result(2);
        unordered_map<int, int> temmap;
        for(int i = 0; i < nums.size(); i++){
            temmap[target - nums[i]] = i;
        }
        for(int j = 0; j < nums.size(); j++){
            if(temmap.count(nums[j]) && temmap[nums[j]] != j){
                result[0] = temmap[nums[j]];
                result[1] = j;
                break;
            }
        }
       return result; 
    }
};