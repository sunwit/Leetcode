class Solution
{
    public:
       Solution()
          {
            srand(time(NULL));
          }
       ListNode *swapPairs(ListNode *head)
       {
         if(random()%2)
           return swapPairs1(head);
         return swapPairs2(head);
       }
       ListNode* swapPairs1(ListNode *head)
       {
         for(ListNode *p = head; p && p->next;p=p->next->next)
           {
             int n = p->val;
             p->val = p->next->val;
             p->next->val = n;
           }
           return head;
       }
       ListNode *swapPairs2(ListNode *head)
       {
         for(ListNode *p = head;p&&p->next;p=p->next)
         {
           ListNode *n = p->next;
           p->next = n->next;
           n->next = p;
         }
         if(head==p)
            head = n;
            return head;
       }
};
