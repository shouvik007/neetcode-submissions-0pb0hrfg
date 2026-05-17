class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        unordered_map<string, int> s; 
        unordered_map<string, string> emailToName; // New: Maps an email to the owner's name
        int id = 0;
        
        for(int i = 0; i < accounts.size(); i++) {
            string name = accounts[i][0];
            for(int j = 1; j < accounts[i].size(); j++){
                string email = accounts[i][j];
                emailToName[email] = name; // Remember who owns this email
                if(s.find(email) == s.end()){ 
                    s[email] = id;
                    id++;
                } 
            }
        }
        
        // New: Reverse lookup array to find an email string from its integer ID
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
                dfs(i, adj, vis, componentIds); // Fixed: Pass by reference to collect IDs
                
                // Convert integer IDs back to email strings
                vector<string> mergedEmails;
                for(int id : componentIds) {
                    mergedEmails.push_back(idToEmail[id]);
                }
                
                // Requirement: Emails must be sorted alphabetically
                sort(mergedEmails.begin(), mergedEmails.end());
                
                // Requirement: The first element must be the Name
                string name = emailToName[mergedEmails[0]];
                mergedEmails.insert(mergedEmails.begin(), name);
                
                ans.push_back(mergedEmails);
            }
        }
        return ans; // Fixed: Missing return statement
    }
    
    // Fixed: Void return type is cleaner since we mutate 'res' via reference directly
    void dfs(int i, vector<vector<int>>& adj, vector<bool>& vis, vector<int>& res) {
        vis[i] = true;
        res.push_back(i);
        for(auto v : adj[i]){
            if(!vis[v]){ // Fixed: Check if neighbor is unvisited
                dfs(v, adj, vis, res); // Fixed: Correct arguments passed
            }
        }
    }
};