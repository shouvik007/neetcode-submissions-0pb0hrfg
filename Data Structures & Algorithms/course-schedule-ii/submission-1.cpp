class Solution {
public:
    stack<int>s;
    bool iscycle(int curr,  vector<vector<int>>& adj, vector<bool>& vis, vector<bool>& rec) {
        vis[curr]=true;
        rec[curr]=true;
        for(auto v:adj[curr]){
            if(!vis[v]){
                if(iscycle(v, adj, vis, rec))
                    return true;
            }
            else if(rec[v]){
                return true;
            }
        }
        rec[curr]=false;
        return false;
    }
    void topologicalsort(int curr, vector<vector<int>>& adj, vector<bool>& vis, stack<int>& s) {
         vis[curr]=true;
         for(auto x:adj[curr]){
            if(!vis[x]){
                topologicalsort(x, adj, vis, s);
            }
         }
         s.push(curr);
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>adj(numCourses);
        for(auto x:prerequisites) {
            adj[x[1]].push_back(x[0]);
        }
        vector<bool>vis(numCourses,false);
        vector<bool>res(numCourses,false);
        for(int i =0;i<numCourses;i++){
            if(!vis[i]){
               if(!iscycle(i,adj, vis, res)) {
                vector<bool>vis2(numCourses, false);
                 topologicalsort(i,adj, vis2, s);
               }
               else {
                return {};
               }
            }
        }
        vector<int>ans;
        while(!s.empty()){
            ans.push_back(s.top());
            s.pop();
        }
        return ans;
    }
};
