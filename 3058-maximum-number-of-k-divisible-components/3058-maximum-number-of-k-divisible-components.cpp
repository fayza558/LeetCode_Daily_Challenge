class Solution {
public:
    vector<vector<int>>adj;
    vector<bool>vis;
    int ans=0;
 int dfs (int node , vector<int>& values,int k)
 {
    vis[node]=true;
    long long sum=values[node];
    for(int child:adj[node]){
        if(vis[child]) continue;
        sum+=dfs(child,values,k);
        sum%=k;
    }
    if(sum%k==0) ans++;
    return sum;
 }
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        adj.resize(n);
        vis.resize(n);
        for(auto it:edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        dfs(0,values,k);
        return ans;

        
    }
};