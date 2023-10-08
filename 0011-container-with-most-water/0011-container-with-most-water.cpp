typedef int ll;
class Solution {
public:
    int maxArea(vector<int>& height) {
        ll i=0,j=height.size()-1;
        ll ans=INT_MIN;
        while(i<j){
            ll area=min(height[i],height[j])*(j-i);
            ans=max(ans,area);
            
            if(height[i]<=height[j])i++;
            else j--;
            
        }
        return ans;
    }
};