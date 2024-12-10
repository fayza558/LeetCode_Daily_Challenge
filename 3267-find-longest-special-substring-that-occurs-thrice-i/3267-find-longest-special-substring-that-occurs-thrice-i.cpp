/*class Solution {
public:
    int maximumLength(string s) {
        for(int i=0;i<s.size();i++)
        {
            for
        }
        
    }
};*/
class Solution {
    int &getMin(int &a,int  &b,int& c){
        if(a<=b and a<=c)   return a;
        if(b<=a and b<=c)   return b;
        return c;
    }
public:
    int maximumLength(string s) {
        int n=s.size();
        vector<vector<int>> top3freq(26,vector<int>(3,-1));

        //Find top-3 substring length for each character (a to z)
        char last_seen = '*';
        int win_len = 0;
        for(char& curr: s){
            int idx = curr-'a';
            win_len = curr==last_seen ? win_len+1 : 1;
            last_seen = curr;
  int &minimum = getMin(top3freq[idx][0],top3freq[idx][1],top3freq[idx][2]);
            if(win_len > minimum)
                minimum = win_len;
        }
        
        //Find the maxLen of substring
        int maxLen=-1;
        for(int i=0;i<26;++i)
 maxLen = max(maxLen,min({top3freq[i][0],top3freq[i][1],top3freq[i][2]}));
        
        return maxLen;
    }
};