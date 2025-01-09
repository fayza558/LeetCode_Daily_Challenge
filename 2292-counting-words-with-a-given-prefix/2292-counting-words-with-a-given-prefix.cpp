class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int cntr=0;
        for(string word:words)
             cntr+=word.substr(0,pref.size())==pref;
        return cntr;
    }
};