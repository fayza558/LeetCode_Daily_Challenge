class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        set<int>sett(banned.begin(),banned.end());
       int sum=0,cntr=0;
        for(int i=1;i<=n;i++)
        {
            if(sett.find(i)==sett.end())
            {
                if(sum+i>maxSum)
                {
                    break;
                }
                sum+=i;
                cntr++;
            }
        }
        return cntr;
        
    }
};
