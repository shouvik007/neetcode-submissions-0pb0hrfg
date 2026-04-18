class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>m;
        for(int i =0;i<nums.size();i++){
            m[nums[i]]++;
        }
        vector<vector<int>>v(nums.size()+1);
        vector<int>ans;
        for(auto x:m){
            v[x.second].push_back(x.first);
        }
        for(int i =v.size()-1;i>=0;i--){
            if(!v[i].empty()){
                for(int num : v[i]){
                    ans.push_back(num);
                    k--;
                    if(k==0){
                        return ans;
                    }
                }
            }
        }
        return ans;
    }
};
