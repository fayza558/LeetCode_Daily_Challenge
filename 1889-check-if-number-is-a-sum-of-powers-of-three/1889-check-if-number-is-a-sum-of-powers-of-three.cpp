class Solution {
public:

    bool checkPowersOfThree(int n) {
        for(int i=15;i>=0;i--){
            if(n>=pow(3,i)){
               n-=pow(3,i);
            }
        }
        return !n;
    }
};