class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        unordered_map<string, int> s; 
        unordered_map<string, string> emailToName;
        int id = 0;
        
        for(int i = 0; i < accounts.size(); i++) {
            string name = accounts[i][0];
            for(int j = 1; j < accounts[i].size(); j++){
                string email = accounts[i][j];
                emailToName[email] = name;
                if(s.find(email) == s.end()){ 
                    s[email] = id;
                    id++;
                } 
            }
        }
        
        vector<string> idToEmail(s.size());
        for(auto& pair : s) {
            idToEmail[pair.second] = pair.first;
        }
        
        vector<vector<int>> adj(s.size());
        for(int i = 0; i < accounts.size(); i++) {
            int index = s[accounts[i][1]]; 
            for(int j = 2; j < accounts[i].size(); j++){
                adj[index].push_back(s[accounts[i][j]]); 
                adj[s[accounts[i][j]]].push_back(index); 
            }
        }
        
        vector<bool> vis(adj.size(), false);
        vector<vector<string>> ans;
        
        for(int i = 0; i < adj.size(); i++){
            if(!vis[i]){  
                vector<int> componentIds;
                dfs(i, adj, vis, componentIds);
                
                vector<string> mergedEmails;
                for(int id : componentIds) {
                    mergedEmails.push_back(idToEmail[id]);
                }
                
                sort(mergedEmails.begin(), mergedEmails.end());
                
                string name = emailToName[mergedEmails[0]];
                mergedEmails.insert(mergedEmails.begin(), name);
                
                ans.push_back(mergedEmails);
            }
        }
        return ans;
    }
    
    void dfs(int i, vector<vector<int>>& adj, vector<bool>& vis, vector<int>& res) {
        vis[i] = true;
        res.push_back(i);
        for(auto v : adj[i]){
            if(!vis[v]){
                dfs(v, adj, vis, res); 
            }
        }
    }
};