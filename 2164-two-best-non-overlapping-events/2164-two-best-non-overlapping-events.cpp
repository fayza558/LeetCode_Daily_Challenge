class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        sort(events.begin(),events.end());
        int n=events.size();
        vector<int>v(n);
        v[n-1]=events[n-1][2];
        for(int i=n-2;i>=0;i--)
        {
           v[i]=max(v[i+1],events[i][2]);
        }
        int maxx=0;
        for(int i=0;i<n;i++)
        {
            vector<int>temp={events[i][1]+1,0,0};
    int j=lower_bound(events.begin(),events.end(),temp)-events.begin();
    if(j!=n)
    {
        maxx=max(maxx,events[i][2]+v[j]);
    }
    maxx=max(maxx,events[i][2]);
        
        }
        return maxx;
    }
};