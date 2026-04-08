class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int res =0;
        int currmin =prices[0];
        for(int i =1;i<prices.size();i++){
            if(prices[i]<currmin){
                currmin = prices[i];
            }
            else {
                res = max(res, prices[i]-currmin);
            }
        }
        return res;
    }
};
