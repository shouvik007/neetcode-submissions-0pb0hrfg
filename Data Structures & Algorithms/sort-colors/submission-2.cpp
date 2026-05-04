class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int l =0;
        int i = 0;
        int r = n-1;
        while(i<=r){
            if(nums[i]==0){
                swap(nums[i],nums[l]);
                l++;
            }
            else if(nums[i]==2){
                swap(nums[i],nums[r]);
                i--;
                r--;
            }
            i++;
        }
    }
};