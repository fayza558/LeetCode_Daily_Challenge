class Solution {
public:
    bool canConstruct(string s, int k) {
        if(k>s.size())return false;
        int freq=0;
        for(char ch:s)
        freq^=(1<<(ch-'a'));
        return __builtin_popcount(freq)<=k;
    }
};