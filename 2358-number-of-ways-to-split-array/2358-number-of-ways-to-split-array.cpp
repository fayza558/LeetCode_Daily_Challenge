class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int n=nums.size(),cntr=0;
        vector<long long >prefix(nums.begin(),nums.end());
        for(int i=1;i<n;i++){
            prefix[i]+=prefix[i-1];
        }
        for(int i=0;i<n-1;i++)
            cntr+=prefix[i]>=(prefix[n-1]-prefix[i]);
      return cntr;
    }
};