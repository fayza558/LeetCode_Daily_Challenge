class Solution {
    int dp[366];
int solve(int i,vector<int>& days, vector<int>& costs){
    if(i==days.size())return 0;
    int &ret=dp[i];
    if(~ret)return ret;
     ret=1e9;
    ret=min(ret,solve(i+1,days,costs)+costs[0]);
    int idx=lower_bound(days.begin(),days.end(),days[i]+7)-days.begin();
    ret =min(ret,solve(idx,days,costs)+costs[1]);
    idx=lower_bound(days.begin(),days.end(),days[i]+30)-days.begin();
    ret=min(ret,solve(idx,days,costs)+costs[2]);
    return ret;
}
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
       memset(dp, -1, sizeof dp);
     return solve(0,days,costs);
    }
};