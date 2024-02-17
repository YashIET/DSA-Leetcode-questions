typedef int ll;
class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        priority_queue<ll>pq;
        for(ll i=0;i<heights.size()-1;i++){
            ll dis=heights[i+1]-heights[i];
            if(dis>0){
                pq.push(-dis);
                if(pq.size()>ladders){
                    //use brick
                    bricks+=pq.top();
                    pq.pop();
                    if(bricks<0)return i;
                }
            }
        }
        return heights.size()-1;
    }
};