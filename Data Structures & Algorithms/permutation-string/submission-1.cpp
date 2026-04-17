class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.size();
        int i = 0;
        vector<int>s1count(26,0);
        vector<int>s2count(26,0);
        for(int i =0;i<n;i++){
            s1count[s1[i]-'a']++;
            s2count[s2[i]-'a']++;
        }
        int j = n-1;
        while(j<s2.size()){
            if(s1count==s2count){
                return true;
            }
            else {
                s2count[s2[i]-'a']--;
                i++;
                j++;
                s2count[s2[j]-'a']++;
            }
        }
        return false;

    }
};
