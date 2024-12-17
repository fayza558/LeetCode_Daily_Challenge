class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        vector<int>freq(26);
        for(char c:s)freq[c-'a']++;
        vector<int>v;
        for(int i=0;i<26;i++) 
           if(freq[i])v.push_back('a'+i);
        s="";
        while(v.size())
        {
            int lst=v.back()-'a';
            v.pop_back();
            int minn=min(repeatLimit,freq[lst]);
            freq[lst]-=minn;
            s+=string(minn,lst+'a');
            if(v.size()&&freq[lst])
            {
                int cur=v.back()-'a';
                s.push_back(cur+'a');
                freq[cur]--;
                if(freq[cur]==0) v.pop_back();
                v.push_back(lst+'a');
            }
        }
        return s;
    }
};