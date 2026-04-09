class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>>ans;
        int n = nums.size();
        for(int i =0;i<n;i++){
            int l =i+1;
            int r = nums.size()-1;
            if(nums[i]>0){
                break;
            }
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            while(l<r){
                int sum = nums[l]+nums[r]+nums[i];
                if(sum==0){
                    
                while(l<r && nums[l]==nums[l+1]) l++;
                while(l<r && nums[r]==nums[r-1]) r--;
                    ans.push_back({nums[l],nums[r],nums[i]});
                    l++;r--;
                }
                
                else if(sum>0) {
                    r--;
                }
                else {
                    l++;
                }
            }
        }
        return ans;
    }
};
