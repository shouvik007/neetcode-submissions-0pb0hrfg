class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        vector<vector<bool>> pacific(n, vector<bool>(m, false));
        vector<vector<bool>> atlantic(n, vector<bool>(m, false));
        queue<pair<int,int>>aq;
        for(int i=0;i<m;i++){
            aq.push({n-1,i});
            atlantic[n-1][i] = true;
        }
        for(int i=0;i<n;i++){
            aq.push({i,m-1});
            atlantic[i][m-1] = true;
        }
        queue<pair<int,int>>q;
        for(int i=0;i<m;i++){
            q.push({0,i});
            pacific[0][i] = true;
        }
        for(int i=0;i<n;i++){
            q.push({i,0});
            pacific[i][0] = true;
        }
        vector<vector<int>>res;
        while(!q.empty()){
            auto top = q.front();
            q.pop();
            int i = top.first;
            int j = top.second;
            if(i+1<n &&!pacific[i+1][j]&& heights[i][j]<=heights[i+1][j]){
                pacific[i+1][j] = true;
                q.push({i+1,j});

            }
            if(i-1>=0&&!pacific[i-1][j]&& heights[i][j]<=heights[i-1][j]){
                pacific[i-1][j] = true;
                q.push({i-1,j});
            }
            if(j+1<m&&!pacific[i][j+1]&& heights[i][j]<=heights[i][j+1]){
                pacific[i][j+  1] = true;
                q.push({i,j+1});
            }
            if(j-1>=0&&!pacific[i][j-1]&& heights[i][j]<=heights[i][j-1]){
                pacific[i][j-1] = true;
                q.push({i,j-1});
            }
        }
         while(!aq.empty()){
            auto top = aq.front();
            aq.pop();
            int i = top.first;
            int j = top.second;
            
            if(i+1<n&& !atlantic[i+1][j]&& heights[i][j]<=heights[i+1][j]){
                atlantic[i+1][j] = true;
                aq.push({i+1,j});
            }
            if(i-1>=0&&!atlantic[i-1][j]&& heights[i][j]<=heights[i-1][j]){
                atlantic[i-1][j] = true;
                aq.push({i-1,j});
            }
            if(j+1<m&&!atlantic[i][j+1]&& heights[i][j]<=heights[i][j+1]){
                atlantic[i][j+1] = true;
                aq.push({i,j+1});
            }
            if(j-1>=0&&!atlantic[i][j-1]&& heights[i][j]<=heights[i][j-1]){
                atlantic[i][j-1] = true;
               aq.push({i,j-1});
            }
        }
        for(int i =0;i<n;i++){
            for(int j =0;j<m;j++){
                if(pacific[i][j] && atlantic[i][j]){
                    res.push_back({i, j});
                }
            }
        }
        return res;

    }
};
