// Problem::Given a singly linked list L: L0→L1→…→Ln-1→Ln,
            // reorder it to: L0→Ln→L1→Ln-1→L2→Ln-2→…
            //
            // You must do this in-place without altering the nodes' values.
            //
            // For example,
            // Given {1,2,3,4}, reorder it to {1,4,2,3}.

#include<bits/stdc++.h>
using namespace std;

/**
 * Definition for singly-linked list.*/
  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };

void reorderList(ListNode* head) {

        ListNode *slow=head,*fast=head;

        if(!head || !head->next)
            return;

        while(fast->next && fast->next->next)
        {
            slow=slow->next;
            fast=fast->next->next;
        }


        ListNode *cur=slow->next, *r=NULL,*t;
        slow->next=NULL;

        while(cur)
        {
            t=cur->next;
            cur->next=r;
            r=cur;
            cur=t;
        }


        ListNode *p=head,*q=r;
        while(p && q)
        {
            t=p->next;
            p->next=q;
            q=q->next;
            p=p->next;
            p->next=t;
            p=p->next;
        }
        return ;
    }
