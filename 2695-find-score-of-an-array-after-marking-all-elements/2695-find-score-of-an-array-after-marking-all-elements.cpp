class Solution {
public:
    long long findScore(vector<int>& nums) {
        int n=nums.size();
        vector<pair<int ,int >>v(n);
        for(int i=0;i<n;i++)
        {
           v[i]={nums[i],i};
        }
        sort(v.begin(),v.end());
        vector<bool>vis(n);
        long long sum=0;
        for(auto [v,i]:v) 
        {
       if(vis[i])continue;
        sum+=v;
        if(i+1<n) vis[i+1]=1;
        if(i-1>=0) vis[i-1]=1;
        }
     return sum;
}
    
};