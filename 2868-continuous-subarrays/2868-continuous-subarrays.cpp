class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        long long sum=0;
        int l=0,r=0,n=nums.size();
        multiset<int>mst;
        while(r<n)
        {
            mst.insert(nums[r++]);
            while(*prev(mst.end())-*mst.begin()>2)
               mst.erase(mst.find(nums[l++]));
            sum+=mst.size();
        }
        return sum;
    }
};