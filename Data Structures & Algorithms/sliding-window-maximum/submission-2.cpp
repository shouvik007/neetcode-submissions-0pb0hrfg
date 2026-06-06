class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        if(n<k){
            return {};
        }
        int l =0;
        int r = k-1;
        vector<int>ans;
        int res = INT_MIN;
        while(r<n){
            if(r-l+1 == k){
                int k = l;
                while(k<=r){
                    res = max(res, nums[k]);
                    k++;
                }
                ans.push_back(res);
                res = INT_MIN;
                r++;
                l++;
            }
            else {
                r++;
            }
            
        }
        return ans;
    }
};
