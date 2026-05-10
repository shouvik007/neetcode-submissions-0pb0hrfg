class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        vector<int>posrem;
        for(int i =0;i<n;i++){
            if(gas[i]-cost[i] >=0){
                posrem.push_back(i);
            }
        }
        for(int i = 0;i<posrem.size();i++){
            if(dfs(posrem[i], gas, cost) == true){
                return posrem[i] ;
            }
        }
        return -1;
    }
    bool dfs(int start, vector<int>& gas, vector<int>& cost) {
        int n  = gas.size();
        int g = 0;
        for(int i =0;i<n;i++){
            int curr = (i+start)%n;
            g = g+gas[curr];
            if(g>=cost[curr]){
                g=g-cost[curr];
            }
            else {
                return false;
            }
        }
        return true;
    }
};
