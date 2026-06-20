int upperBound(vector<int>& nums, int x) {
    int low = 0, high = nums.size() - 1;
    int ans = nums.size();

    while(low <= high) {
        int mid = low + (high - low) / 2;

        if(nums[mid] > x) {
            ans = mid;
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }

    return ans;
}
