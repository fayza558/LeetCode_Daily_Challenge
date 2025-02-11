class Solution {
public:
    string removeOccurrences(string s, string part) {
      int sz=part.size();
      string ans;
      for(char ch:s){
        ans.push_back(ch);
        if(ans.size()>=sz&&ans.substr(ans.size()-sz)==part){
            ans.erase(ans.size()-sz);
        }
      }
      return ans;
    }
};