class Solution {
public:
bool isVowel (char ch){
    return ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u';
}
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
       int n=words.size() ;
       vector<int>prefix(n);
       for(int i=0;i<n;i++){
        prefix[i]=isVowel(words[i][0])&isVowel(words[i].back());
        if(i)prefix[i]+=prefix[i-1];
       }
       int q=queries.size();
       vector<int>ans(q);
       for(int i=0;i<q;i++){
       int l=queries[i][0],r=queries[i][1];
       ans[i]=prefix[r]-(l?prefix[l-1]:0);
       }
       return ans;
    }
};