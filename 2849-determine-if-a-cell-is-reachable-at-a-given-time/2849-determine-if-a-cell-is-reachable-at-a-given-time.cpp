class Solution {
public:
    typedef int ll;
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
        ll diffX=abs(sx-fx);
        ll diffY=abs(sy-fy);
        if(diffX==0 && diffY==0){
            return t != 1;
        }
        if(diffX<=t && diffY<=t){
            return true;
        }
        
        return false;
    }
};