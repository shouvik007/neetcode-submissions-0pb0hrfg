class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.empty()) return 0;
        vector<int>v(128,0);
        int l =0;
        int res = INT_MIN;
        for(int h =0;h<s.size();h++){
            v[s[h]]++;
            while(v[s[h]]>1){
                v[s[l]]--;
                l++;
            }
            res = max(res,h-l+1 );
        }
        return res;
    }
};
