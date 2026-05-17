class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        if(k == nums.size()){
            return;
        }
        else {
            if(k>nums.size()){
                k = k%(nums.size());
            }
            while(k--){
                int prev = nums[0];
                for(int i =1;i<n;i++){
                    int curr = nums[i];
                    nums[i] = prev;
                    prev = curr;
                }
                nums[0]=prev;
            }
        }
    }
};