class Solution {
   public:
    string minWindow(string s, string t) {
        int n = s.size();
        int l = 0;
        vector<int> v(128, 0);
        for (int i = 0; i < t.size(); i++) {
            v[t[i]]++;
        }
        int minimum = INT_MAX;
        int size = 0;
        int start = 0;
        int len = t.size();
        for (int r = 0; r < n; r++) {
            if (v[s[r]] > 0) {
                len--;
            }
            v[s[r]]--;
            while (len ==0) {
                if(minimum > (r-l+1)){
                    minimum = r-l+1;
                    start = l;
                }
                v[s[l]]++;
                if(v[s[l]]>0){
                    len++;
                }
                l++;
            }
        }
         return minimum == INT_MAX ? "" : s.substr(start, minimum);
    }
};
