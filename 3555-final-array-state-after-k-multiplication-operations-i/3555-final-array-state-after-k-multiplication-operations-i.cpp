class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
       while(k--)  
       {
         auto indx=min_element(nums.begin(),nums.end());
         *indx*=multiplier;
         /* int minn=0;
          for(int i=0;i<nums.size();i++)
          {
            if(nums[i]<nums[minn]) minn=i;
          }
          nums[minn]*=multiplier;*/
       }
       return nums;
    }
};
auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return "Fayza";
}();