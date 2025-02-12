class Solution {
public:
    int maximumSum(vector<int>& nums) {
        int n=nums.size(),ans=-1;
        vector<pair<int,int>>v;
        v.reserve(n);
        for(auto x:nums){
            int temp=x,sum=0;
            while(temp)sum+=temp%10,temp/=10;
            v.push_back({sum,x});
        }
        sort(v.begin(),v.end());
        for(int i=1;i<n;i++){
            if(v[i].first==v[i-1].first)
            ans=max(ans,v[i].second+v[i-1].second);
        }
        return ans;
    }
};