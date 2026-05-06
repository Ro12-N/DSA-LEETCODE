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
    ListNode* rotateRight(ListNode* head, int k) {
       int len=0;
       ListNode* t=head;
       while(t){
        t=t->next;
        len++;
       }  
       if(len==0) return head; 
       k=k%len;
       if(k==0) return head;
       k=len-k;
       ListNode* d=t;
       t=head;

       while(k--){
        d=t;
          t=t->next;
       }
       d->next=NULL;
       d=t;
       while(t->next) t=t->next;
       t->next=head;
       return d;
    }
};
// TC : O(n) where n is the number of nodes in the input linked list
// SC : O(1) as we are using only constant space to store the temporary variables