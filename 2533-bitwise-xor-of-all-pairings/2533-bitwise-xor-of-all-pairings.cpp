
class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int ans=0;
        int m=nums2.size();
        if(m&1){
            for(int ele: nums1)
                ans^=ele;
        }

        //Find contribution by second array elements
        int n=nums1.size();
        if(n&1){
            for(int ele: nums2)
                ans^=ele;
        }
        return ans;
    }
};