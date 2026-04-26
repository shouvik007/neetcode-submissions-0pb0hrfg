class Solution {
public:
    
    int maxSubarraySumCircular(vector<int>& nums) {
        int n = nums.size();
        int m = INT_MIN;
        for(int i =0;i<n;i++){
            
        int currsum =0;
            for(int j=0;j<n;j++){
                currsum = currsum+nums[(i+j)%n];
                m = max(currsum , m);

            }
        }
        return m;
    }
};