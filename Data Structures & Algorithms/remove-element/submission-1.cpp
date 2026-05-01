class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n = nums.size();
        int l =0;
        int r = n-1;
        while(l<=r){
            if(nums[r]==val){
                r--;
            }
            else if(nums[l]==val && nums[r]!=val){
                swap(nums[l],nums[r]);
                l++;
            }
            else if(nums[l]!=val){
                l++;
            }
        }
        int count =0;
        for(int i =0;i<n;i++){
            if(nums[i]!=val){
                count ++;
            }
        }
        return count;
    }
};