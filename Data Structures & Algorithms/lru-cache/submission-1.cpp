
    class Node {
        public:
        int a;
        int b;
        Node* next;
        Node* prev;
        Node(int x, int y){
            a=x;
            b=y;
            next = nullptr;
            prev = nullptr;
        }
    };    
    class LRUCache {
    private:
        int cap;
        unordered_map<int, Node*> cache;
        Node* head;
        Node* tail;
    public:
        
        LRUCache(int capacity) {
            cap = capacity;
            head = new Node(-1,-1);
            tail = new Node(-1,-1);
            head->next = tail;
            tail->prev=head;
        }
        
        int get(int key) {
            if(cache.find(key)==cache.end()){
                return -1;
            }
            else {
                Node* temp = cache[key];
                delNode(temp);
                addNode(temp);
                return temp->b;
            }
        }
        void addNode(Node* newNode) {
            Node* oldNext = head->next;
            head->next = newNode;
            oldNext->prev = newNode;
            newNode->prev = head;
            newNode->next = oldNext;
        }
        void delNode(Node* oldNode){
            Node* prevNode = oldNode->prev;
            Node* nextNode = oldNode->next;
            prevNode->next = oldNode->next;
            nextNode->prev = prevNode;
            oldNode->next = nullptr;
            oldNode->prev=nullptr;
        }
        void put(int key, int value) {
            Node* newNode = new Node(key,value);
            if(cache.find(key)!=cache.end()){
                Node* oldNode = cache[key];
                delNode(oldNode);
                cache.erase(key);
                delete oldNode;
            }
            if(cache.size()==cap){
                Node* oldNode = tail->prev;
                cache.erase(tail->prev->a);
                delNode(oldNode);
            }
            addNode(newNode);
            cache[key]=newNode;
        }
    };