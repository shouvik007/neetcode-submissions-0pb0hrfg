class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int>prefix(n);
        vector<int>suffix(n);
        int curr = 1;
        for(int i=0;i<nums.size();i++){
            prefix[i]= curr ;
            curr = curr*nums[i];
        }
        curr =1;
        for(int i =n-1;i>=0;i--) {
            suffix[i]=curr;
            curr=curr*nums[i];
        }
        for(int i =0;i<n;i++){
            prefix[i]=prefix[i]*suffix[i];
        }
        return prefix;
    }
};
