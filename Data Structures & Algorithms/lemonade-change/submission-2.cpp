class Solution {
public:
    bool lemonadeChange(vector<int>& nums) {
        vector<int>v(21,0);
        int n = nums.size();
        for(int i =0;i<n;i++){
            if(nums[i]==5){
                v[5]++;
            }
            else if(nums[i]==10){
                v[10]++;
                if(v[5]<1){
                    return false;
                }
                else {
                    v[5]--;
                }
            }
            else if(nums[i]==20){
                v[20]++;
                if(v[5]>2){
                    v[5]=v[5]-3;
                }
                else if(v[5]>=1 && v[10]>=1){
                    v[5]=v[5]-1;
                    v[10] = v[10]-1;
                }
                else {
                    return false;
                }

            }
        }
        return true;
    }
};