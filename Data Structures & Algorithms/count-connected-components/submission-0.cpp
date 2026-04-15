class Solution {
public:
    void dfs(vector<vector<int>>& adj, vector<bool>&vis, int curr){
        vis[curr]=true;
        for(auto x: adj[curr]) {
            if(!vis[x]){
                dfs(adj, vis, x);
            }
        }
    }
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<bool>vis(n,false);
        vector<vector<int>>adj(n);
        for(auto x:edges){
            adj[x[1]].push_back(x[0]);
            adj[x[0]].push_back(x[1]);
        }
        int count =0;
        for(int i =0;i<n;i++){
            if(!vis[i]){
                count++;
                dfs(adj,vis,i);
            }
        }
        return count;
    }
};
