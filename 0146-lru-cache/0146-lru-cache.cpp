typedef int ll;
class LRUCache {
public:
    
    class node{
        public:
        ll key;
        ll val;
        node* next;
        node* prev;
        node (ll key_,ll value_){
            key=key_;
            val=value_;
            
        }
        
    };
    ll cap;
    node * head=new node(-1,-1);
    node *tail=new node(-1,-1);
    unordered_map<ll,node*>m;
    void deletenode(node* delnode){
        delnode->prev->next=delnode->next;
        delnode->next->prev=delnode->prev;
    }
    
    void addnode(node *newnode){
        newnode->next=head->next;
        newnode->prev=head;
        newnode->next->prev=newnode;
        head->next=newnode;
    }
    LRUCache(int capacity) {
        cap=capacity;
        head->next=tail;
        tail->prev=head;
    }
    
    int get(int key) {
        //check in map if key exits :-->
        //                              then first get its address from hasmap then delete that
        //                              node from map as well as from doubly linked list
        //                              then insert it next to head node and add the new 
        //                              address in hasmap becase it is referred most recently
        //              else return -1;
            if(m.find(key)!=m.end()){
                node *resnode=m[key];
                ll res=resnode->val;
                m.erase(key);
                deletenode(resnode);
                addnode(resnode);
                m[key]=head->next;
                return res;
            }
        return -1;
    }
    
    void put(int key, int value) {
        if(m.find(key)!=m.end()){
            node *resnode=m[key];
            m.erase(key);
            deletenode(resnode);
        }
        if(m.size()==cap){
            m.erase(tail->prev->key);
            deletenode(tail->prev);
        }
        addnode(new node(key,value));
        m[key]=head->next;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */