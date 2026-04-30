class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        int n = nums.size();
        vector<int>v(2*n,0);
        int l =0;
        for(int i =0;i<v.size();i++){
            if(i<=n-1){
                v[i]=nums[i];
            }
            else {
                v[i]=nums[i%n];
            }
        }
        return v;
    }
};