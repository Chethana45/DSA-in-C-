class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        
        int maxs=nums[0];
        int currentsum=nums[0];
        for(int i=1;i<nums.size();i++){
            currentsum=max(nums[i],nums[i]+currentsum);
            maxs=max(currentsum,maxs);
        }
        return maxs;
    }
};
