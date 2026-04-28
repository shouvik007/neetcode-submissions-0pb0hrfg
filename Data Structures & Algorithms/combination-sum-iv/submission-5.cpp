class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<int>v(target+1,-1);
       return  find(nums, target,v);
    }
    int find(vector<int>&nums,int target,vector<int>&v){
       if(target ==0){
        return 1;
       }
       if(target<0){
            return 0;
       }
       if(v[target]!=-1){
        return v[target];
       }
       int count = 0;
       for(int i =0;i<nums.size();i++){
            count = count + find(nums , target-nums[i],v);
       }
       return v[target]=count;
    }
};