class Solution {
public:
int minimum = INT_MAX;
    void findbinary(vector<int> &nums, int l , int h){
        if(l>=h){
            minimum = min(minimum, nums[l]);
            return ;
        }
        int mid = (l+h)/2;
        minimum = min(minimum, nums[mid]);
        findbinary(nums, mid+1,h);
        findbinary(nums,l, mid-1);

    }
    int findMin(vector<int> &nums) {
        int l =0;
        int h = nums.size()-1;
        findbinary(nums, l,h);
        return minimum;
    }
};
