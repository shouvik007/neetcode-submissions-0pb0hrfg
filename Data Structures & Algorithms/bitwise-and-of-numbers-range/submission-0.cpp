class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int x = left;
        for(int i = left+1; i<=right;i++){
            x= x&(i);
        }
        return x;
    }
};