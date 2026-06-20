class Solution {
public:
    int searchInsert(vector<int> &nums, int target)  {
        int low=0;
        int high=nums.size()-1;
        int ans= nums.size();
        while(low<=high){
            int mid=low+(high-low)/2;
            if(nums[mid]==target){
                ans=mid;
                return ans;
            }
            else if(nums[mid]>target){
                high=mid-1;
            } 
            else{
low = mid+1;
            }
        }
       return low;
    }
};
