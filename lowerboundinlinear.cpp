int lowerBound(vector<int>& nums, int x) {
    for(int i = 0; i < nums.size(); i++) {
        if(nums[i] >= x)
            return i;
    }
    return -1;
}
