class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
       int up=upper_bound(nums.begin(),nums.end(),target)-nums.begin();
       if(up>=1 and nums[up-1]!=target) return up;
       if(up<1) return 0;
       return up-1;
    }
};