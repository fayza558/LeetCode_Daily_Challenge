class Solution {
public:
    bool divideArray(vector<int>& nums) {
        map<int,int>mp;
        for(int num:nums){
            mp[num]++;
        }
        for(const auto &pair:mp){
            if(pair.second%2!=0){
                return false;
            }
        }
        return true;
    }
};