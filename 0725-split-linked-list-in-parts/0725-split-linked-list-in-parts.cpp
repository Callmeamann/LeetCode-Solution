/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*> list(k);
        ListNode* itr = head,*temp;
        int count =0 ;
        while(itr){
            count++;
            itr= itr->next;
        }
        vector<int> indx(k,count/k);
        for(int i=0 ; i<count%k ;i++)
            indx[i]++;
        itr = head;
        temp = head;
        int idx = 0;
        while(itr){
            list[idx] = temp;
            for(int i=0 ; i<indx[idx]-1 ; i++){
                itr = itr->next;
            }
            idx++;
            temp = itr->next;
            itr->next = NULL;
            itr = temp;
        }
        return list;
    }
};