class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l= 0;
        int h = nums.size()-1;
        if(nums.size()==0){
            return -1;
        }
        while(l<=h){
            int mid = (l+h)/2;
            if(nums[mid]==target){
                return mid;
            }
            else if(nums[mid]>=nums[l]){
                if(nums[mid]>target && target >=nums[l])
                    h = mid-1;
                else {
                    l = mid+1;
                }
            }
            else {
                if(nums[mid]<target && target<=nums[h])
                    l = mid+1;
                else {
                    h = mid-1;
                }
            }
        }
        return -1;
    }
};
