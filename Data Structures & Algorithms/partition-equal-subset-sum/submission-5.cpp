class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int total =0;
        int n = nums.size();
        for(int i =0;i<n;i++){
            total = nums[i]+total;
        }
        if(total%2!=0){
            return false;
        }
        vector<vector<int>>v(nums.size(), vector<int>((total/2)+1,-1));
        return find((total/2), nums, 0,0,v);
    }
    bool find(int target, vector<int>& nums, int sum,int i,vector<vector<int>>& v ){
        if(i==nums.size() || sum>target){
            return false;
        }
        if(sum == target){
            return true;
        }
        if(v[i][sum]!=-1){
            return v[i][sum];
        }
        int include_sum = nums[i]+sum;
        int exclude_sum = sum;
        
        bool result =((find(target, nums, include_sum , i+1,v) ) || (find(target, nums, exclude_sum , i+1,v))) ;
        return v[i][sum]= result;
        return v[i][sum];
    }
};
