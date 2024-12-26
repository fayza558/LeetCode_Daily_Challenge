class Solution {
public:
    int dp[21][3001];

    int solve(int idx,int target ,vector<int>& nums){
        if(idx==nums.size()) return target==1000;
        if(~dp[idx][target])return dp[idx][target];
       return  dp[idx][target]= solve(idx+1,target+nums[idx],nums)+ solve(idx+1,target-nums[idx],nums);
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        memset(dp,-1,sizeof dp);
        return solve(0,target+1000,nums);
    }
};