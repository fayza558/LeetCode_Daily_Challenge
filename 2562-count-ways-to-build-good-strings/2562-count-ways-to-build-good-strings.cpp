class Solution {
    int dp[100001];
    int MOD = 1000000007;

    int countWays(int &low,int &high,int &zero,int &one,int pos){
        if(pos>high)    return 0;
        if(dp[pos]!=-1) return dp[pos];

        int count = 0;  //Count ways from current position
        if(pos>=low)    count++;    //Add 1 if current string is good
        count += countWays(low,high,zero,one,pos+zero);//Extend by 0s
        count += countWays(low,high,zero,one,pos+one); //Extend by 1s

        return dp[pos] = count % MOD;
    }
public:
    int countGoodStrings(int low, int high, int zero, int one) {
        memset(dp,-1,sizeof(dp));
        return countWays(low,high,zero,one,0);
    }
};