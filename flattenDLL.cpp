class Solution {
public:
    Node* flatten(Node* head) {
        if(head == NULL){
            return head;
        }

        Node* curr = head;
        while(curr != NULL){
            if(curr->child != NULL){
                // flatten the child nodes
                Node* next = curr->next;
                Node* child = flatten(curr->child);
                curr->next = child;

                if (child) child->prev = curr;
                curr->child = NULL;

                // find tail
                Node* temp = curr;
                while(temp->next != NULL){
                    temp = temp->next;
                }

                // attach tail with next ptr
                if(next != NULL){
                    temp->next = next;
                    next->prev = temp;
                }
            }
            curr = curr->next;
        }
        return head;
    }
};

