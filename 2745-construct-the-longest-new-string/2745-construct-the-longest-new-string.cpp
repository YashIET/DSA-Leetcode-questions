class Solution {
public:
    typedef int ll;
    int longestString(int x, int y, int z) {
        ll mini = min(x,y);
        ll ans=0;
        ans+=4*mini;
        if(x!=y)ans+=2;
        ans+=2*z;
        return ans;
    }
       
    
};