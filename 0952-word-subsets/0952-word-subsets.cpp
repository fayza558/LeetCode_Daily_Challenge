class Solution {
public:
    vector<int>solve(string &s){
        vector<int>v(26);
        for(char ch:s){
            v[ch-'a']++;
        }
        return v;
    }
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<int>freq(26);
        for(string s:words2){
            vector<int>temp=solve(s);
            for(int i=0;i<26;i++){
                freq[i]=max(freq[i],temp[i]);
            }
        }
        vector<string>ans;
        for(string s:words1){
            vector<int>temp=solve(s);
            bool ok =true;
            for(int i=0;i<26;i++){
                if(freq[i]>temp[i])ok=false;
            }
            if(ok) ans.push_back(s);
        }
        return ans;
    }
};