class Node{
public:
    int val;
    Node *next;
    Node(int x){
        val = x;
        next = NULL;
    }
};

class MyLinkedList {
public:
    Node *head;
    int size;
    MyLinkedList() {
        head = new Node(0);
        size = 0;
    }
    
    int get(int index) {
        if(index < 0 || index >= size)
            return -1;
        Node *temp = head;
        for(int i = 0; i < index; i++){
            temp = temp->next;
        }
        return temp->val;
    }
    
    void addAtHead(int val) {
        addAtIndex(0, val);
    }
    
    void addAtTail(int val) {
        addAtIndex(size, val);
    }
    
    void addAtIndex(int index, int val) {
        Node *temp = head;
        Node *newNode = new Node(val);
        if(index < 0 || index > size){
            return;
        }
        
        if(index == 0){
            newNode->next = temp;
            head = newNode;
        }
        else{
            for(int i = 0; i < index-1; i++){
                temp = temp->next;
            }
            newNode->next = temp->next;
            temp->next = newNode;
        }
        
        size++;
    }
    
    void deleteAtIndex(int index) {
        Node *current = head;

        if(index < 0 || index >= size)
            return;
        
        // If delete at head, need to update head
        if(index == 0){
            Node *temp = head->next;
            delete head;
            head = temp;
        }
        else{
            for(int i = 0; i < index-1; i++){
                current = current->next;
            }
            Node *temp = current->next->next;
            delete current->next;
            current->next = temp;
        
        }
        size--;
        
    }
    
    // Destructor
    // Deallocate memory
    ~MyLinkedList(){
        Node *prev = head;
        while(prev != NULL){
            head = head->next;
            delete prev;
            prev = head;
        }
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */