class Solution {
   bool solve(string &s,vector<string>&nums){
        if(s.size()==nums.size())
           return find(nums.begin(),nums.end(),s)==nums.end();
     //   return max(solve(s+"0",nums),solve(s+"1",nums));
     s.push_back('0');
     if(solve(s,nums)) return true;
     s.pop_back();
     s.push_back('1');
     if(solve(s,nums)) return true;
     s.pop_back();
     return false;
    }
public:
    string findDifferentBinaryString(vector<string>& nums) {
        string s;
        solve(s,nums);
        return s;
    }
};