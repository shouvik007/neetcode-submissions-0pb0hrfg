class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int m = nums.size();
        if(m==0){
            return {};
        }
        unordered_map<int,int>mp;
        for(int i =0;i<m;i++){
            mp[nums[i]]++;
        }
        vector<vector<int>>v(nums.size()+1);;vector<int>ans;
        for(auto x:mp){
            v[x.second].push_back(x.first);
        }
        for(int i =v.size()-1;i>=0;i--){
            for(int x: v[i]){
                ans.push_back(x);
                if(k==ans.size()) return ans;
            }
        }
        return ans;
    }
};
