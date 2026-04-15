class Solution {
public:
    bool iscycle( vector<vector<int>>&adj, vector<bool>&vis, int curr, int parent) {
        vis[curr]=true;
        for(auto v:adj[curr]){
            if(!vis[v]) {
                if(iscycle(adj, vis, v, curr)) {
                    return true;
                }
            }
            else {
                if(v!=parent){
                    return true;
                }
            }
        }
        return false;
    }
    bool validTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>>adj(n);
        for(auto x:edges){
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }
        vector<bool>vis(n,false);
            if(iscycle(adj,vis, 0,-1)){
                return false;
        }
        for(int i =0;i<n;i++){
            if(vis[i]==false){
                return false;
            }
        }
    return true;
    }
};
