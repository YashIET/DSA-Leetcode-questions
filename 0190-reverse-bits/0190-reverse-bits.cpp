class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        for(int i=0;i<16;i++){
            uint32_t a,b;
            a=(1<<i)&n ;
            b=(1<<(32-i-1))&n;
            (a)!= 0 ? n=n|(1<<(32-i-1)  ):  n=n&(~(1<<(32-i-1)));
            (b)!= 0 ? n=n|(1<<(i)  ):  n=n&(~(1<<(i)));
        }
        return n;
    }
};