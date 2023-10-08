typedef int ll;
class Solution {
public:
    int getSum(int a, int b) {
        ll ans=0;
        ll k=0;
        unsigned carry=0;
        ll aise=0;
        while((a || b || carry) && k<32){
            ll l1=(a&1);
            ll l2=(b&1);
            
            if(l1==1 && l2==1 && carry==1){
                carry=1;
                aise=1;
            }
            else if(l1==1 && l2==1 && carry==0){
                carry=1;
                aise=0;
            }
            else if((l1==1 || l2==1) && carry==1){
                carry=1;
                aise=0;
            }
            else if((l1==1 || l2==1) && carry==0){
                carry=0;
                aise=1;
            }
            else if(l1==0 && l2==0 && carry==1){
                carry=0;
                aise=1;
            }
            else{
                carry=0;
                aise=0;
            }
            
            ans=ans|(aise==1 ? (1<<k):0);
            // ans=ans<<1;
            // ans+=aise;
            
            a=a>>1;
            b=b>>1;
            // cout<<aise<<" "<<carry<<endl;
            k++;
        }
        // if(carry==1){
        //     ans=ans<<1;
        //     ans+=1;
        // }
        
        return ans;
    }
};