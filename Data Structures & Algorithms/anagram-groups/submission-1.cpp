class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>>m;
        for(auto& s:strs){
            string sorteds = s;
            sort(sorteds.begin(),sorteds.end());
            m[sorteds].push_back(s);
        }
        vector<vector<string>>ans;
        for(auto& x:m){
            ans.push_back(x.second);
        }
        return ans;
    }
};
