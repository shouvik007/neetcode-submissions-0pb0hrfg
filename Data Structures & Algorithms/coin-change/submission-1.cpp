class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        unordered_set<int> v;
        queue<int>q;
        q.push(amount);
        int step =0;
        while(!q.empty()){
            int s = q.size();
            while(s--) {
            int x = q.front();
            q.pop();
            if(x==0){
                return step;
            }
            if(x<0||v.count(x)){
                continue;
            }
            v.insert(x);
            for(auto i : coins){
                q.push(x-i);
            }
            }
            step++;
        }
    return -1;
    }
};
