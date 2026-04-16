class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        map<int,int>m;
        if(n ==0 || n==1){
            return n;
        }
        for(int i =0;i<n;i++){
            m[nums[i]]++;
        }
        int l =0;
        int res = INT_MIN;
        while(l<n){
            int count =1;
            int x = nums[l];
            if(m.find(x-1)==m.end()){
                while(m.count(x+1)){
                    count++;
                    x= x+1;
                }
                res = max(res,count);
            }
            l++;
        }
        return res;
    }
};
