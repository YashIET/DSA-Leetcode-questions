typedef int ll;
class Solution {
public:
    //Naive---------------------->
    //for each height in histogram see largest rectangle including this much height
    //basically see in left which is first smaller than current height and simmilarly find in
    //right which is first smaller in right and through this we find length of rec now just         //multiply with curremt heigght to get this rectangle heigth
    //but checking these (first left smaller and first right smaller takes big(N) time each
    //time and we do that for all elements 
    //Time complexity-->O(N^2)
    
    //Optimised----------------->
    //use concept of next smaller element on right and left and store them before iterating to       //the main array 
    int largestRectangleArea(vector<int>& heights) {
        ll n=heights.size();
        vector<ll>left(n,-1),right(n,-1);
        stack<ll>s1,s2;
        //catch --> here we have stored indexes instead of nos to get boundary
        //          also we have stored upto which max index i can take elements on standing at 
        //          index i by using st.top()-1 in right[i]; Similarly for left
        for(ll i=0;i<n;i++){
            while(!s1.empty() && heights[s1.top()]>=heights[i]){
                s1.pop();
            }
            if(!s1.empty())left[i]=s1.top()+1;
            else left[i]=0;
            s1.push(i);
        }
        for(ll i=n-1;i>=0;i--){
            while(!s2.empty() && heights[s2.top()]>=heights[i]){
                s2.pop();
            }
            if(!s2.empty())right[i]=s2.top()-1;
            else right[i]=n-1;
            s2.push(i);
        }
        ll ans=INT_MIN;
        for(ll i=0;i<n;i++){
            ll area=heights[i]*(right[i]-left[i]+1);
            ans=max(ans,area);
        }
        return ans;
    }
};