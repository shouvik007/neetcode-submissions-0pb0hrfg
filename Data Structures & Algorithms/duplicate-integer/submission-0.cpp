class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_map<int,int>occur;
        for(int i =0;i<nums.size();i++){
            occur[nums[i]]++;
        }
        for(auto x:occur){
            if((x.second)>1){
                return true;
            }
        }
        return false;
    }
};