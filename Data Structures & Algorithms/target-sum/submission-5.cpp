class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        return fun(0,nums,target, 0 );
    }
    int fun(int i,vector<int>& nums, int target, int sum){
        if(i==nums.size()&& sum != target){
            return 0;
        }
        if(sum == target && i ==nums.size()){
            return 1;
        }
        int pos = fun(i+1, nums, target, sum + nums[i]);
        int neg = fun(i+1, nums, target, sum - nums[i]);
        return pos+neg;

    }
};
