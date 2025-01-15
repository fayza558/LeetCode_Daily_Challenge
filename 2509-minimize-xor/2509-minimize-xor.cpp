class Solution {
public:
    int minimizeXor(int num1, int num2) {
        int count=__builtin_popcount(num2);
        
        int i;
        int fres=0;
        for(int i=31;i>=0;i--)
        {
            if(num1 & (1<<i)  and count)
            {
                
                fres|=(1<<i);
                count--;
            }
        }
        for(i=0;i<=31 and count;i++)
        {
            if(!(fres & (1<<i)))
            {
                fres|=(1<<i);
                count--;
            }
        }
            
     
        return fres;
    }
};