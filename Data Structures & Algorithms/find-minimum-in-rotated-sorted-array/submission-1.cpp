class Solution {
public:
    int findMin(vector<int>& nums) {
        int l = 0;
        int h = nums.size() - 1;
        
        while (l < h) {
            int mid = l + (h - l) / 2; // Prevents potential integer overflow
            
            if (nums[mid] > nums[h]) {
                // Minimum is in the right part, mid cannot be the minimum
                l = mid + 1;
            } else {
                // Minimum is at mid or in the left part
                h = mid;
            }
        }
        
        // When l == h, we've narrowed it down to the smallest element
        return nums[l];
    }
};
