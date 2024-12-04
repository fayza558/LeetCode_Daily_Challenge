class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) {
        int i=0,j=0,n=str1.size(),m=str2.size();
        while(i<n&&j<m)
        {
            char nxt =str1[i];
            nxt++;
            if(nxt>'z')nxt='a';
            if(str1[i]==str2[j])
            {
                i++;
                j++;
            }
           else if(nxt==str2[j])
            {
                i++;
                j++;
            }else i++;
        }
        return j==m ;
        
    }
};