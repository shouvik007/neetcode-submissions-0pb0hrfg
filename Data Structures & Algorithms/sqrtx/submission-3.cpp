class Solution {
public:
    int mySqrt(int x) {
        return find(1,x,x);
    }
    int find(int l, int h, int x){
        if(l>h){
            return h;
        }
        int mid=  l + (h - l) / 2;
        if((long long)mid*mid == x){
            return mid;
        }
        else if((long long)mid*mid > x) {
            return find(l,mid-1,x);
        }
        else{
            return find(mid+1,h,x);
        }
    }
};