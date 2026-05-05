class Solution {
public:
    string addBinary(string a, string b) {
        int carry = 0;
        //int n = (a.size()>b.size())?a.size():b.size();
        int i = a.size()-1;
        int j = b.size()-1;
        string res ="";
        while(i>=0 || j>=0 ||carry){
            int sum = carry;
            if(i>=0){
                sum= sum+ (a[i]-'0');
                i--;
            } 
            if(j>=0){
                sum= sum+ (b[j]-'0');
                j--;
            }
            res = res+char((sum%2)+'0');
            carry = sum/2;
        }
         reverse(res.begin(),res.end());
         return res;
    }
};