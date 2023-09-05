/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* itr = head , *nextItr;
        // Intertwining of old and new list
        while(itr != NULL){
            nextItr = itr->next;
            Node* temp = new Node(itr->val);
            itr->next = temp;
            temp->next = nextItr;

            itr = nextItr;
        }

        // Intertwining random pointers of new list 
        itr = head;
        while(itr != NULL){
            if(itr->random != NULL){
                itr->next->random = itr->random->next;
            }
            itr = itr->next->next;
        }

        //removing old list
        itr = head;
        Node* newHead = new Node(0);
        Node* copy , *cItr = newHead;
        while(itr){
            nextItr = itr->next->next;
            copy = itr->next;
            cItr->next = copy;
            cItr = copy;

            itr->next = nextItr;
            itr = nextItr;
        }

        return newHead->next;
    }
};