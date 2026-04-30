class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        return ifreach(nums, n , 0);
    }
    bool ifreach(vector<int>& nums ,int n , int i){
        if(i==n-1){
            return true;
        }
        if(i!=n-1 && nums[i]==0){
            return false;
        }
        else {
            for(int j =1;j<=nums[i];j++){
                if(ifreach(nums, n, i+j)){
                    return true;
                }
            }
        }
        return false;
    }
};
