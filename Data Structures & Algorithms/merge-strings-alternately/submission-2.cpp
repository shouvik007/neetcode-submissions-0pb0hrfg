class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int l =0;
        string res ="";
        int n1 = word1.size();
        int n2 = word2.size();
        while((l<n1)||(l<n2)){
            if(l<n1){
                res = res+word1[l];
            }
            if(l<n2){
                res = res+word2[l];
            }
            l++;
        }
        return res;
    }
};