class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int i =0;
        int j = 1;
        int res =0;
        while(i<=n-2){
            if(prices[j]-prices[i]<0){
                if(j!=(n-1)){
                    i++;
                    j++;
                }
                else {
                    i++;
                }
            }
            else {
                res= res+prices[j]-prices[i];
                i++;j++;
            }
            
        }
        return res;
    }
};