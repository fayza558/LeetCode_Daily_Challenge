class Solution {
public:
 //brute force
    int solve(int idx,int target ,vector<int>& nums){
        if(idx==nums.size()) return !target;
       return  solve(idx+1,target+nums[idx],nums)+ solve(idx+1,target-nums[idx],nums);
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        return solve(0,target,nums);
    }
};