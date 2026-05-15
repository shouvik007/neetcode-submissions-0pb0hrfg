class Solution {
public:
    bool isSame(string& word1, string& word2  ){
        if(word1.size() != word2.size()){
            return false;
        }
        int i =0;int j =0;
        int count = 0;
        while(i<word1.size() && j<word2.size()){
            if(word1[i]!=word2[j]){
                count++;
            }
            i++;
            j++;
        }
        if(count == 1){
            return true;
        }
        return false;
    }
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        vector<vector<int>>v(wordList.size());
        int n = wordList.size();
        for(int i =0;i<n;i++){
            for(int j =i+1;j<n;j++){
                    if(isSame(wordList[i], wordList[j])){
                        v[i].push_back(j);
                        v[j].push_back(i);
                    }
            }
        }
        queue<pair<int, int>> q; // {index, distance}
        vector<bool> vis(n, false);
        for(int i = 0; i < n; i++) {
            if(isSame(beginWord, wordList[i])) {
                q.push({i, 2});
                vis[i] = true;
            }
        }
        if (beginWord == endWord) return 1;
        while(!q.empty()){
            auto [curr, dis] = q.front();
            q.pop();
            if(wordList[curr] == endWord){
                return dis;
            }
            for(auto x : v[curr]){
                if(vis[x]!=true){
                    vis[x]=true;
                    q.push({x, dis+1});
                }
            }
        }
        return 0;
    }

};
