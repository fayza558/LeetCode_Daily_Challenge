class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        vector<int>pre=arr,suf=arr;
        int n=arr.size();
        for(int i=1;i<pre.size();i++)
        {
            pre[i]=max(pre[i],pre[i-1]);
        }
          for(int i=n-2;i>=0;i--)
        {
            suf[i]=min(suf[i],suf[i+1]);
        }
        int cntr=0;
        for(int i=0;i<arr.size()-1;i++)
        {
             cntr+=pre[i]<suf[i+1];
        }
        return cntr+1;
    }
};