class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
         if(n ==0 || n==1){
            return n;
        }
        unordered_map<int,int>m;
        for(int i =0;i<n;i++){
            m[nums[i]]++;
        }
        int ans = 0;
        for(int i=0;i<n;i++){
            if(m.find(nums[i]-1)==m.end()){
                int count  =1;
                int x = nums[i]+1;
                while(m.count(x)){
                    count++;
                   
                    x++;
                }
                 ans = max(ans, count);
            }
        }
        return ans;
    }
};
