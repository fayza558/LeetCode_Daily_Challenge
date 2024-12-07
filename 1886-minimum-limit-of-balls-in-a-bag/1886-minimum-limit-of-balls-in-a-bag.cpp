class Solution {
public:
    int minimumSize(vector<int>& nums, int maxOperations) {
         int st=1,ed=*max_element(nums.begin(),nums.end()),cur=-1,mid;
         while(st<=ed)
         {
            mid=(st+ed)/2;
            int operations =0;
            for(auto bag:nums)
            {
                operations+=(bag-1)/mid;
                
            }
            if(operations<=maxOperations)
            {
                cur=mid;
                ed=mid-1;
            }else st=mid+1;
         }
         return cur;
    }
    
};