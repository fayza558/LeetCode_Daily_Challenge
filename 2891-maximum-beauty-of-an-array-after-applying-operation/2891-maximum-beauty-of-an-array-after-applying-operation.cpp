
class Solution {
    #define pii pair<int,int>
public:
    int maximumBeauty(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());

        //Sliding window
        int max_count=0;
        int win_count=0;
        int left=0,right=0;
        int n=nums.size();
        while(right<n){
            //Find valid window of max size
            while(right<n and (nums[right]-nums[left])<=2*k){
                win_count++;
                right++;
            }
            
            max_count = max(max_count,win_count);
            if(right==n) break;

            //Skip left to again make window valid
            while(left<=right and (nums[right]-nums[left])>2*k){
                win_count--;
                left++;
            }
        }
        return max_count;
    }
};



