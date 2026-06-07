class Solution {
public:
    int secondLargestElement(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int largest=nums[n-1];
        for(int i=n-2;i>=0;i--){
            if(nums[i]!=largest){
                return nums[i];
            }
        }
      return -1;
    }
};
