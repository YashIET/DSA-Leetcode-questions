typedef int ll;
class Solution {
public:
    int getSum(int a, int b) {
        if(b==0)return a;
        ll sum=a^b;
        ll carry=(a&b)<<1;
        return getSum(sum,carry);
    }
};