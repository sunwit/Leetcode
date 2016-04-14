class Solution
{
    public:
       if(head==NULL || n<=0)
         return NULL;
       ListNode fakeHead(0);
       fakeHead.next=head;
       head = &fakeHead;
       ListNode *p1, *p2;
       p1=head;
       p2=head;
       for(int i=0; i<n;i++)
       {
         if(p2==NULL) return NULL;
         p2=p2->next;
       }
       while(p2->next!=NULL)
       {
         p2=p2->next;
         p1=p1->next;
       }
       p1->next = p1->next->next;
       return head->next;
}
