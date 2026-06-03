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
        while(r<n ){
            int maximum = INT_MIN;
            int k = l;
            while(k<=r){
                maximum =  max(nums[k],maximum);
                k++;
            }
            ans.push_back(maximum);
            r++;
            l++;
        }
        return ans;
    }
};
