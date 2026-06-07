class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n=nums.size();
        k=k%n;
        reverse(nums,nums+k);
        reverse(nums+k,nums+n);
        reverse(nums,nums+n);
        
    }
};
