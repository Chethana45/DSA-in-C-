class Solution {
public:
    int mostFrequentElement(vector<int>& nums) {
        unordered_map<int,int> mpp;
        for(int i=0;i<nums.size();i++){
            mpp[nums[i]]++;
        }
   
        int max=0;
        int ans= INT_MAX;
        for(auto it:mpp){
            int element= it.first;
            int frequency= it.second;
            if(frequency>max){
                max=frequency;
                ans=element;
            }
            if(frequency==max){
                ans=min(ans,element);
            }

        }
return ans;
    }
};
