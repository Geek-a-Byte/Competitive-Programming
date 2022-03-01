class Solution {
public:
    int search(vector<int>& nums, int target) {
        int mid, ans = -1;
        int l=0;
        int r=nums.size();
        while (l < r)
        {
            mid = (l + r) / 2;
            //base case
            if (nums[mid]==target)
            {
                ans = mid;
                //to get first occurence we have to go to left
                r = mid;
            }
            else if (target < nums[mid])
            {
                r = mid;
            }
            else
                l = mid + 1;
        }
        return ans;
    }
};