class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int>res(temperatures.size(),0);
        int n = temperatures.size();
        int l =0;
        int h = l+1;
        while(l<n){
            if(h>=n){
                res[l]=0;
                l++;
                h = l+1;
            }
            if(temperatures[l]<temperatures[h]){
                res[l]=(h-l);
                l++;
                h= l+1;
            }
            else {
                h++;
            }
        }
        res[n-1]=0;
        return res;
    }
};
