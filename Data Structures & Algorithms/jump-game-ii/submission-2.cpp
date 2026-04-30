class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int>v(n, -1);
        return minJump(nums, 0,n,v);
    }
    int minJump(vector<int>& nums, int i,int n, vector<int>& v){
        if(i>=n-1) {
            return 0;
        }
        if(v[i]!=-1){
            return v[i];
        }
        if(i!=n-1 && nums[i]==0){
            v[i] =  INT_MAX;
            return v[i];
        }
        int count = INT_MAX;
        for(int j=1;j<=nums[i];j++){
            int next = minJump(nums,i+j,n,v);
            if(next != INT_MAX)
                count = min(count, 1+next);
        }
        v[i]=count;
        return v[i];
    }
};
