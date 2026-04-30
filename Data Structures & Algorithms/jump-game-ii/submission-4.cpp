class Solution {
public:
    int jump(vector<int>& nums) {
        int l =0;
        int n = nums.size();
        int r =0;
        int count = 0;
        while(r<nums.size()-1){
            int far = 0;
            for(int i =l;i<=r;i++){
                far = max(i+nums[i], far);
            }
            l = r+1;
            r = far;
            count++;
        }
        return  count;
    }
};
