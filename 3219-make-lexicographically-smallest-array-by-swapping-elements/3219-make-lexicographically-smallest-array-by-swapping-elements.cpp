class Solution {
    #define pii pair<int,int>
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n=nums.size();
        //Step-1: Find location of each number
        vector<pii> copy;
        for(int i=0;i<n;++i)
            copy.push_back(make_pair(nums[i],i));
        
        //Step-2: Get ordered array with their original array index
        sort(copy.begin(),copy.end());

        //Step-3: Find groups and place ordered values
        int left=0,right=1;
        while(right<n){
            //Find group and get their original array indices
            vector<int> pos={copy[left].second};
            while(right<n and abs(copy[right].first-copy[right-1].first)<=limit){
                pos.push_back(copy[right].second);
                right++;
            }
            //Order indices
            sort(pos.begin(),pos.end());

            //Place ordered values to ordered indices in original array
            for(int i=0;i<right-left;++i)
                nums[pos[i]]=copy[left+i].first;
            
            left=right;
            right++;
        }
        return nums;
    }
};