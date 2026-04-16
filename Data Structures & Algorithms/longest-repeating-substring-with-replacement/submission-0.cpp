class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        vector<int>v(26,0);
        int l =0;
        int res = INT_MIN;
        int maxfreq = 0;
        for(int i =0;i<n;i++){
            v[s[i]-'A']++;
            maxfreq = max(maxfreq,  v[s[i]-'A']);
            while((i-l+1)-(maxfreq)>k){
                v[s[l]-'A']--;
                l++;
            }
            res = max(res, i-l+1);
        }
        return res;
    }
};
