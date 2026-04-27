class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int total =0;
        int n = nums.size();
        for(int i =0;i<n;i++){
            total = nums[i]+total;
        }
        if(total%2!=0){
            return false;
        }
        return find((total/2), nums, 0,0);
    }
    bool find(int target, vector<int>& nums, int sum,int i){
        if(i==nums.size()){
            return false;
        }
        if(sum == target){
            return true;
        }
        int include_sum = nums[i]+sum;
        int exclude_sum = sum;
        
        if(find(target, nums, include_sum , i+1) ) {
          
            return true;
        }
        else if(find(target, nums, exclude_sum , i+1)) {
            
            return true;
        }
        return false;
    }
};
