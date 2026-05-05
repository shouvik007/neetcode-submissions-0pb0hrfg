class Solution {
public:
    vector<int> countBits(int n) {
        vector<int>v(n+1,0);
        for(int i =0;i<=n;i++) {
            v[i]= count(i);
        }
        return v;
    }
    int count(int n ){
        if(n==0){
            return 0;
        }
        if(n==1){
            return 1;
        }
        int count =0;
        while(n!=0){
            n = n&(n-1);
            count++;
        }
        return count;
    }
};
