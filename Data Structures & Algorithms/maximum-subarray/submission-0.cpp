class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int m = INT_MIN;
        int currsum =0;
        int n = nums.size();
        for(int i=0;i<n;i++){
            currsum = currsum+nums[i];
            m = max(m, currsum);
            if(currsum<0){
                currsum =0;
            }
        }
        return m;
    }
};
