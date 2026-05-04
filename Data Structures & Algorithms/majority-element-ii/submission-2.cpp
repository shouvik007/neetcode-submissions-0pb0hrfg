class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int>v;
        int n =nums.size();
        int mj1 = -1;
        int mj2 = -1;
        int c1 =0;
        int c2 = 0;
        for(int i =0;i<n;i++){
            if (nums[i]==mj1){
                c1++;
            }
            else if(nums[i]==mj2){
                c2++;
            }
            else if(c1 ==0 ){
                mj1=nums[i];
                c1=1;
            }
            else if(c2 ==0 ){
                mj2=nums[i];
                c2=1;
            }
            else{
                c1--;
                c2--;
            }
        }
        c1=c2=0;
        for(int i =0;i<n;i++){
            if(nums[i]==mj1){
                c1++;
            }
            else if(nums[i]==mj2){
                c2++;
            }
        }
        if(c1>(n/3)){
            v.push_back(mj1);
        }
        
        if(c2>(n/3)){
            v.push_back(mj2);
        }
        return v;
    }
};