class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int>m;
        for(int i =0;i<nums.size();i++){
            m[nums[i]]=i;
        }
        for(int i =0;i<nums.size();i++){
            int x = target-nums[i];
            if(m.find(x)!=m.end() && m[x]!=i){
                return {i,m[x]};
            }
        }

    }
};
