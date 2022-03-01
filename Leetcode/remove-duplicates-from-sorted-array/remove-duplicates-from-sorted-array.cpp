class Solution {
public:
    long long int removeDuplicates(vector<int>& nums) {
        if(nums.size()==0 or nums.size()==1) return nums.size();
        long long int j=0;
        long long int i=0;
        while(i<nums.size()-1){
        while(i<nums.size()-1 and nums[i]==nums[i+1])
        {        
            i++;
        }
        nums[j]=nums[i];
        j++;
        i++;
    }
    if(nums[nums.size()-2]!=nums[nums.size()-1]){
        nums[j]=nums[i];
        j++;
    }
    return j;
}
};