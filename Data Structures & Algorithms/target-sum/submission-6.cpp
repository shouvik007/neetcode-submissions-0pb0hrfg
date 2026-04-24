class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int total_sum = 0;
        for(int i =0;i<nums.size();i++){
            total_sum = total_sum + nums[i];
        }
        int offset =total_sum;
        vector<vector<int>>v(nums.size(),vector<int>(2*total_sum+1, -1));
        return fun(0,nums,target, 0 , v, offset);
    }
    int fun(int i,vector<int>& nums, int target, int sum,vector<vector<int>>&v,int offset){
        if(i==nums.size()&& sum != target){
            return 0;
        }
        if(sum == target && i ==nums.size()){
            return 1;
        }
        if(v[i][offset+sum]!=-1){
            return v[i][offset+sum];
        }
        int pos = fun(i+1, nums, target, sum + nums[i],v , offset);
        int neg = fun(i+1, nums, target, sum - nums[i],v, offset);
        v[i][sum + offset] = pos + neg;
        return v[i][sum + offset];

    }
};
