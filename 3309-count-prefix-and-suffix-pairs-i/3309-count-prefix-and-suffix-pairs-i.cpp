class Solution {
inline bool isPrefixAndSuffix (string &a,string &b){
    if(a.size()>b.size())return 0;
    return b.substr(0,a.size())==a&&b.substr(b.size()-a.size())==a;
}
public:
    int countPrefixSuffixPairs(vector<string>& words) {
     int cntr=0;
     for(int i=0;i<words.size();i++){
        for(int j=i+1;j<words.size();j++){
          cntr+=isPrefixAndSuffix(words[i],words[j]);
        }
     }
     return cntr;
    }
};