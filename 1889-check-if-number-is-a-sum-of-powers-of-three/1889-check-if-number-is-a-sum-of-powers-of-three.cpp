class Solution {
public:
bool solve(int p,int n){
    if(!n) return true;
    if(p<0||n<0)return false;
    return solve(p-1,n-pow(3,p))|solve(p-1,n);
}
    bool checkPowersOfThree(int n) {
        return solve(15,n);
    }
};