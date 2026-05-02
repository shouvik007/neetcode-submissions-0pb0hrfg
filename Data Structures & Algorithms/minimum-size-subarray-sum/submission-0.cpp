class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int t =0;
        for(int i =0;i<nums.size();i++){
            t=t+nums[i];
        }
        if(t<target){
            return 0;
        }
        t=0;
        int l =0;
        int res = INT_MAX;
        int n = nums.size();
        for(int r=0;r<n;r++){
            t= t+nums[r];
            while(target<=t){
                res = min(res, r-l+1);
                t = t- nums[l];
                l++;
            }
        }
    return res;
    }
};