class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> visit;
        while(visit.find(n) == visit.end()){
            visit.insert(n);
            int x = dfs(n);
            if(x==1){
                return true;
            }
            else {
                n = x;
            }
        }
        return false;
    }
    int dfs(int n ){
        int sum =0;
        while(n>=1){
            int t = n%10;
            sum = sum + t*t;
            n = n/10;
        }
        return sum;
    }
};
