class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int flib=0,ans=0,n=nums.size();
        for(int i=0;i<n;i++)
        {
            if(i>=k&&nums[i-k]==99)
            {
                flib--;
            }
            if(nums[i]==(flib&1))
            {
                if(i+k>n)
                {
                    return -1;
                }
                flib++;
                nums[i]=99;//#
                ans++;
            }
        }
        return ans;
        
    }
};