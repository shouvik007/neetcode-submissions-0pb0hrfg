class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        vector<bool>vis(n, false);
        return ifreach(nums, n , 0,vis);
    }
    bool ifreach(vector<int>& nums ,int n , int i, vector<bool>& vis){
        if(i==n-1 ){
            return true;
        }
        if(i!=n-1 && nums[i]==0){
            return false;
        }
        else if(vis[i]!=true) {
            for(int j =1;j<=nums[i];j++){
                if(ifreach(nums, n, i+j,vis)){
                    return true;
                }
            }
            vis[i]=true;
        }
        return false;
    }
};
