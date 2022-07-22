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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* it = head;
        ListNode* pre = nullptr, *after = nullptr, *reverse_head, *reverse_end;
        int cnt = 0, length = 0; 
        while(it){
            it = it->next;
            length++;
        }
        
        it = head;
        while(it){
            cnt++;
            if(cnt == left - 1) pre = it;
            if(cnt == left) reverse_head = it;
            if(cnt == right) reverse_end = it;
            if(cnt == right + 1) after = it;
            it= it->next;
        }
        reverse_end -> next = nullptr;
        
        // it = head;
        // cout << reverse_head -> val << reverse_end -> val;
        reverse(reverse_head);
        // cout << reverse_head -> val << reverse_end -> val;
        if (pre) pre -> next = reverse_end;
        else head = reverse_end;
        reverse_head -> next = after;
        return head;
    }
    
    void reverse(ListNode* head){
        ListNode* node = head, *pre=nullptr, *cur=head, *after=head->next;
        while(cur){
            after = cur->next;
            cur -> next = pre;
            pre = cur;
            cur = after;
        }
    }
};