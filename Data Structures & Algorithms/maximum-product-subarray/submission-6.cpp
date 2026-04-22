class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n= nums.size();
        if(n==0){
            return 0;
        }
        int res = nums[0];
        int minimum = nums[0];
        int maximum = nums[0];
        for(int i =1;i<n;i++) {
            if(nums[i]<0){
                swap(maximum, minimum);
            }
            maximum = max(maximum*nums[i],nums[i]);
            minimum = min(nums[i], minimum*nums[i]);
            res = max(res, maximum);
        }
        return res;
    }
};
