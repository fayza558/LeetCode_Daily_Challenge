class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
    vector<int>v1;
    vector<int>v2;
    int cntrp=0;
    for(int i=0;i<nums.size();i++){
        if(nums[i]<pivot){
            v1.push_back(nums[i]);
        }else if(nums[i]>pivot){
            v2.push_back(nums[i]);
        }else{
            cntrp++;
        }
    }

    int indx=0;
    for(int num:v1){
        nums[indx++]=num;
    }
    while(cntrp--){
        nums[indx++]=pivot;
    }
    for(int num:v2){
        nums[indx++]=num;
    }
 return nums;
    }
};