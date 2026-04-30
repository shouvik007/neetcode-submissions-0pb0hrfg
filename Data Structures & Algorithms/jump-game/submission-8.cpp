class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int curr = n-2;
        int prev = n-1;
        while(curr>=0){
            if(curr+nums[curr]>=prev){
                prev = curr;
                
            }
            curr--;
        }
    return prev == 0;
    }
};
