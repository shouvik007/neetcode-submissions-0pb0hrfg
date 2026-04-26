class Solution {
public:
    
    int maxSubarraySumCircular(vector<int>& nums) {
        int n = nums.size();
        int m = INT_MAX;
        int mx=INT_MIN;
        int t =0;
        int currsum=0;
        for(int i =0;i<n;i++){
            currsum = max(nums[i],currsum+nums[i]);
            mx = max(mx,currsum);
        }
         currsum=0;
        for(int i =0;i<n;i++){
            t= t+nums[i];
            currsum = min(nums[i],currsum+nums[i]);
            m = min(m,currsum);
        }
        if(mx<0){
            return mx;
        }
        return max(mx,t-m);
    }
};