#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<iostream>
#include<vector>

using namespace std;

struct ListNode
{
  int val;
  ListNode *next;
  ListNode(int x): val(x), next(NULL) {}
};

ListNode* mergeTwoLists(ListNode* head1, ListNode* head2);
ListNode* mergeTwoLists1(ListNode* head1, ListNode* head2);
 //ListNode* mer(ListNode* head1, ListNode* head2);
ListNode *mergeKLists(vector<ListNode *> &lists)
{
    ListNode *p, *p1, *p2;
    while(lists.size()>1)
    {
      p1 = lists.back();
      lists.pop_back();
      p2 = lists.back();
      lists.pop_back();
      p = mergeTwoLists(p1,p2);
      lists.insert(lists.begin(), p);
    }
    return lists.size()==1?lists[0]:NULL;
}

void TakeOutNode(ListNode*& head, ListNode*& tail, ListNode*& p)
{
   ListNode *pNext = p->next;
   if(head == NULL)
    head = tail = p;
   else
     {
       tail->next = p;
       tail = p;
     }
     p->next = NULL;
     p = pNext;
}

 ListNode *mergeTwoLists2(ListNode*& head1, ListNode*& head2)
{
 ListNode *p1 = head1, *p2 = head2;
 ListNode *pHead = NULL, *pTail = NULL;
 while(p1 && p2)
 {
     if(p1->val < p2->val)
       TakeOutNode(pHead, pTail,p1);
     else
        TakeOutNode(pHead,pTail,p2);
 }
 ListNode *p = NULL;
 if(p1)
    p = p1;
 else
    p = p2;
 if(pHead == NULL)
    return p;
 pTail->next = p;
 return pHead;
}

static int n = random()%2;
ListNode *mergeTwoLists(ListNode *head1, ListNode *head2)
{
  if(!n)
  {
     return mergeTwoLists1(head1,head2);
  }
  else
    return mergeTwoLists2(head1, head2);
}

ListNode *mergeTwoLists1(ListNode *head1, ListNode *head2)
{
  ListNode *p1 = head1, *p2 = head2;
  static ListNode dummy(0);
  dummy.next = p1;
  ListNode *prev = &dummy;

  while(p1 && p2)
  {
    if(p1->val < p2->val)
     {
       prev = p1;
       p1 = p1->next;
     }
     else
     {
       prev->next = p2;
       p2 = p2->next;
       prev = prev->next;
       prev->next = p1;
     }
  }
  if(p2)
    prev->next = p2;
  return dummy.next;
}




void printList(ListNode *h)
{
  while(h!=NULL)
  {
     printf("%d ", h->val);
     h = h->next;
  }
  printf("\n");
}

ListNode *createList(int a[], int n)
{
   ListNode *head = NULL, *p = NULL;
   for(int i = 0; i<n; i++)
   {
     if(head == NULL)
       head = p = new ListNode(a[i]);
     else
        {
          p->next = new ListNode(a[i]);
          p = p->next;
        }
   }
   return head;
}


int main(int argc, char **argv)
{
   srand(time(NULL));
   if(argc>1)
      n = atoi(argv[1])%2;
   int a[] = {1, 3, 5, 6, 7, 10};
   int b[] = {0, 4, 6, 8, 9, 11, 20, 30, 40};
   ListNode *p1 = createList(a, sizeof(a)/sizeof(int));
   ListNode *p2 = createList(b, sizeof(b)/sizeof(int));
   printList(mergeTwoLists(p1,p2));

   vector<ListNode*> v;
   for(int i = 0;i<8;i++)
      v.push_back(new ListNode(random()%100));
  printList(mergeKLists(v));
  cout<<"method"<<n+1<<endl;
  return 0;
}
