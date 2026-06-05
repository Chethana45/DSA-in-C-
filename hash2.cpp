class Solution {
public:
    vector<vector<int>> countFrequencies(vector<int>& nums) {
        // Your code goes here
       unordered_map<int,int> mpp;
       for(int i=0;i<nums.size();i++){
        mpp[nums[i]]++;
       }
       vector<vector<int>> ans;
       for(auto it:mpp){
        ans.push_back({it.first,it.second});
       }
return ans;
    }
};
