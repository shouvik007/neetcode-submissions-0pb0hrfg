class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int l =0;
        int n = nums.size()-1;
        int r =l+1;
        vector<vector<int>>v(nums.size());
        sort(nums.begin(),nums.end());
        int count =0;
        while(r<=n){
            if(nums[l]==nums[r]) {
                r++;
            }
            else {
                count = ((r-1)-l);
                v[count].push_back(nums[l]);
                l=r;
                count = 0;
            }
        }
        count = ((r-1)-l);
            v[count].push_back(nums[l]);
        vector<int> result;
        for (int i = n; i >= 0 && result.size() < k; i--) {
            for (int num : v[i]) {
                result.push_back(num);
                if (result.size() == k) return result;
            }
        }
        return result;

    }
};
