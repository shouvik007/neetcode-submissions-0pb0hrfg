class Solution {
public:
    int mySqrt(int x) {
        if (x < 2) {
            return x;
        }

        int l = mySqrt(x >> 2) << 1;
        int r = l + 1;
        return (long long) r * r > x ? l : r;
    }
};