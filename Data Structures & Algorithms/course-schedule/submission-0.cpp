class Solution {
public:
    bool ifcycle(int curr,vector<vector<int>>&adj, vector<bool>rec, vector<bool>vis) {
        vis[curr]=true;
        rec[curr] = true;
        for(auto v:adj[curr]){
            if(!vis[v]){
                if(ifcycle(v,adj, rec, vis)){
                    return true;
                }
            }
            else if(rec[curr]){
                return true;
            }
        }
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int v = numCourses;
        vector<vector<int>>adj(v);

        for(auto x:prerequisites){
            adj[x[1]].push_back(x[0]);
        }
        vector<bool>vis(v,false);
        vector<bool>rec(v,false);
        for(int i =0;i<v;i++){
                if(ifcycle(i,adj, rec, vis)) {
                return false;
            }
        }
        return true;
    }
};
