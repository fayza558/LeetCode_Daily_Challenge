class Solution {
    vector<int> prefix_sum;
    int max_sum;
    int mem[20001][3];//[pos][count]

    int findMaxSum(vector<int>& nums,int pos,int count,int& k){
        if(count==3)              return 0;
        if(pos>nums.size()-k)     return 0;
        if(mem[pos][count]!=-1)   return mem[pos][count];
        
        //Don't start subarray here
        int dont_start = findMaxSum(nums,pos+1,count,k);

        //Start subarray here
        int start_here = findMaxSum(nums,pos+k,count+1,k)
                         + prefix_sum[pos+k]-prefix_sum[pos];

        return mem[pos][count] = max(dont_start,start_here);
    }
    void findMaxSumPath(vector<int>& nums,int pos,int count,int& k,vector<int>& path){
        if(count==3)             return;
        if(pos>nums.size()-k)    return;

        //Don't start subarray here
        int dont_start = findMaxSum(nums,pos+1,count,k);//In O(1) time

        //Start subarray here
        int start_here = findMaxSum(nums,pos+k,count+1,k)//In O(1) time
                         + prefix_sum[pos+k]-prefix_sum[pos];
        
        //Choose optimal path
        if(start_here >= dont_start){
            path.push_back(pos);
            findMaxSumPath(nums,pos+k,count+1,k,path);//Include pos
        }else{
            findMaxSumPath(nums,pos+1,count,k,path);//Don't include pos
        }
    }
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        memset(mem,-1,sizeof(mem));

        //Calculate Prefix-Sum
        prefix_sum = vector<int>(n+1,0);
        for(int i=0;i<n;++i)
            prefix_sum[i+1] = prefix_sum[i]+nums[i];

        //Find max_sum value
        max_sum = findMaxSum(nums,0,0,k);

        //Find subarray start indices with max_sum value
        vector<int> path;
        findMaxSumPath(nums,0,0,k,path);
        
        return path;
    }
};