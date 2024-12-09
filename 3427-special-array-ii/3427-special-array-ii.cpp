class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        int n=nums.size();
        vector<int>index;
        for(int i=1;i<n;i++)
        {
            if((nums[i]&1)==(nums[i-1]&1))
            {
                index.push_back(i);
            }
        }
        vector<bool>ans(queries.size(),true);
        for(int i=0;i<queries.size();i++){
            int l=queries[i][0];
            int r=queries[i][1];
            if(l==r)continue;
            auto it =upper_bound(index.begin(),index.end(),l);
            if(it!=index.end()&&*it<=r)
            {
                ans[i]=false;
            }
        }
        return ans;
    }
};