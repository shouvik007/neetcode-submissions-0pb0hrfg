class Solution {
public:
    int numSquares(int n) {
        vector<int>v(n+1,n);
        v[0]=0;
        if(n==0){
        return 0;
       } 
       int res = n;
       for(int i =1;i<=n;i++){
            for(int s = 1; s*s<=i;s++){
                v[i]=min(v[i],1+v[i-s*s]);
            }
       }
       return v[n];
    }
};