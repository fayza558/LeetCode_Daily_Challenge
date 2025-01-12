class Solution {
public:
    bool canConstruct(string s, int k) {
        if(k>s.size())return false;
        vector<int>freq(26);
        int odd=0;
        for(char ch:s)freq[ch-'a']++;
        for(int i=0;i<26;i++)
           if(freq[i]&1)
             odd++;
        return odd<=k;
        
    }
};