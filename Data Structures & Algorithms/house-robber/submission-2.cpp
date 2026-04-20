class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int>v(n);
        v[0]=nums[0];
        v[1]=max(nums[1],nums[0]);
        for(int i =2;i<n;i++){
            v[i]=max(nums[i]+v[i-2], v[i-1]);
        }
        return v[n-1];
    }
};
