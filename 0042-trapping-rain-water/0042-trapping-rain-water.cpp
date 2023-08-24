class Solution {
public:
    typedef int ll;
    //just need to calculate min(max(left height),max(right height)-current height)
    //brute force would be doing this for all i and at particular i we will traverse in left and right to find left max height and right max height 
    //time-->O(n ^ 2)
    
    //better would be to store left max and right max as prfix max array and suffix max array
    //time -->O(n)
    //space-->O(2*n)--prefix and suffix array
    
    //best solution
    int trap(vector<int>& height) {
        ll left=0,right=height.size()-1;
        ll result=0;
        ll maxLeft=0,maxRight=0;
        while(left<=right){
            if(height[left]<=height[right]){
                if(height[left]>=maxLeft)maxLeft=height[left];
                else result+=maxLeft-height[left];
                left++;
            }
            else{
                if(height[right]>=maxRight)maxRight=height[right];
                else result+=maxRight-height[right];
                right--;
            }
        }
        return result;
    }
};