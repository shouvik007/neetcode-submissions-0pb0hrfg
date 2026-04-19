class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 0;
        int n = nums.size();
        int curr = 0;
        for(int i =0;i<n;i++){
            if(count ==0){
                curr = nums[i];
                count++;
            }
            else if(curr==nums[i]){
                count++;
            }
            else {
                count --;
            }
        }
        return curr;
    }
};