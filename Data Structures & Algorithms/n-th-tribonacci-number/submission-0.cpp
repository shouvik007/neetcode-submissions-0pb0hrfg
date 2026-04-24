class Solution {
public:
    int tribonacci(int n) {
        if(n==0){
            return 0;
        }
        if (n == 1 || n == 2) return 1;
        vector<int>v(n+1,-1);
        v[0]=0;
        v[1]=1;
        v[2]=1;
        return tri(v, n);
    }
    int tri( vector<int>&v , int n ){
        if(v[n]!=-1){
            return v[n];
        }
        else {
            v[n]= tri(v,n-1)+tri(v,n-2)+tri(v,n-3);
        }
        return v[n];
    }
};