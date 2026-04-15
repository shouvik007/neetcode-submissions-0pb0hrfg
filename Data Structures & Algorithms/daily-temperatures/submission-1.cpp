class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<pair<int,int>>s;
        vector<int> res(temperatures.size(), 0);
        int n =temperatures.size();
        for(int i =0;i<n;i++){
            int t = temperatures[i];
            while(!s.empty()&& s.top().first<t){
                auto p = s.top();
                s.pop();
                res[p.second] = i - p.second;
            }
            s.push({t, i});
        }
        return res;
    }
};
