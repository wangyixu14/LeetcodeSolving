class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int ori = 0;
        vector<int> mod1(nums.begin(), nums.end());
        vector<int> mod2(nums.begin(), nums.end());
        for(int i = 0; i < nums.size() - 1; i++){
            if(nums[i] > nums[i+1]) {
                mod1[i] = nums[i+1];
                mod2[i+1] = nums[i];
                break;
            }
        }
        bool opt1 = true, opt2 = true;
        for(int i = 0; i < nums.size() - 1; i++){
            if(mod1[i] > mod1[i+1]) opt1 = false;
            if(mod2[i] > mod2[i+1]) opt2 = false;
        }
        return opt1 or opt2;
    }
};