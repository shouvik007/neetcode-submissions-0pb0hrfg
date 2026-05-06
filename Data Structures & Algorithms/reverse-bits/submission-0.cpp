class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t res = 0;
        for(int shift = 31; shift>=0;shift --){
                uint32_t bit = n&1;
                res = res +(bit<<shift);
                n=n>>1;
        }
        return res;
    }
};
