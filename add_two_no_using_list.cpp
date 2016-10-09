
 struct ListNode {
     int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

    ListNode *head;
   ListNode *current = new ListNode(0);
   head = current;

   int carry=0;

   while(l1 || l2)
   {
       current->val=carry;
       if(l1)
       {
           current->val+=l1->val;
           l1=l1->next;
       }
       if(l2)
       {
           current->val+=l2->val;
           l2=l2->next;
       }

       carry=current->val/10;
       current->val=current->val%10;

       if(l1 || l2 || (carry > 0))
       {
          current->next = new ListNode(carry);
          current = current->next;
       }

   }

   return head;

}
