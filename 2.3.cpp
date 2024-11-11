#include <iostream>
using namespace std;

struct LinkNode
{
    int val;
    LinkNode* next;
};

LinkNode* createNode(int data)
{
    LinkNode* newNode=new(LinkNode);
    newNode->val=data;
    newNode->next=nullptr;
    return newNode;
}

LinkNode* createLink(int a[],int len)
{
    LinkNode* head=createNode(a[0]);
    LinkNode* cur=head;
    for (int i=1;i<len;i++)
    {
        cur->next=createNode(a[i]);
        cur=cur->next;
    }
    return head;
}

void outputLink(LinkNode* head)
{
    LinkNode* cur=head;
    while (cur!=nullptr)
    {
        cout << cur->val << " ";
        cur=cur->next;
    }
    cout << endl;
}

LinkNode* Link_mix(LinkNode* head_a,LinkNode* head_b)
{
    LinkNode *head=nullptr;
    while (head_a!=nullptr && head_b!=nullptr)
    {
        if (head_a->val < head_b->val)
        {
            LinkNode* temp=head_a;
            head_a=head_a->next;
            temp->next=head;
            head=temp;
        }
        else
        {
            LinkNode* temp=head_b;
            head_b=head_b->next;
            temp->next=head;
            head=temp;
        }
    }
    while (head_a!=nullptr)
    {
        LinkNode* temp=head_a;
        head_a=head_a->next;
        temp->next=head;
        head=temp;
    }
    while (head_b!=nullptr)
    {
        LinkNode* temp=head_b;
        head_b=head_b->next;
        temp->next=head;
        head=temp;
    }
    return head;
}

int main()
{
    int a[]={1,5,8,23,57};
    int b[]={3,9,11,26};
    int len_a=sizeof(a)/sizeof(a[0]);
    int len_b=sizeof(b)/sizeof(b[0]);
    LinkNode* head_a=createLink(a,len_a);
    LinkNode* head_b=createLink(b,len_b);
    LinkNode* head=Link_mix(head_a,head_b);
    outputLink(head);
    return 0;
}
