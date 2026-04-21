class Solution {
   public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        if (n == 1) return nums[0];
        if (n == 2) return max(nums[0], nums[1]);
        // if (nums[0] > nums[n - 1]) {
        //     start = 0;
        //     end = n - 2;
        // } else {
        //     start = 1;
        //     end = n - 1;
        // }
        vector<int> v(n - 1);
        v[0] = nums[0];
        v[1] = max(nums[0], nums[1]);
        for (int i = 2; i <n-1; i++) {
            v[i] = max((nums[i] + v[i - 2]), v[i - 1]);
        }
        vector<int> v2(n - 1);
        v2[0] = nums[1];
        v2[1] = max(nums[1], nums[2]);
        for (int i = 3; i <=n-1; i++) {
            v2[i-1] = max((nums[i] + v2[i - 3]), v2[i - 2]);
        }

        return max(v[v.size() - 1], v2[v2.size()-1]) ;
    }
};
