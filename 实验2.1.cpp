#include<iostream>
using namespace std;

struct LinkNode
{
    int val;
    LinkNode *next;
    LinkNode(int x) :val(x),next(nullptr){}
};

LinkNode* initial_llink(int data[],int size_d)
{
    if (size_d<=0)
        return NULL;
    LinkNode* head=new LinkNode(data[0]);
    LinkNode* cur=head;
    for (int i=1;i<size_d;i++)
    {
        cur->next=new LinkNode(data[i]);
        cur=cur->next;
    }
    return head;
}

void print_LinkNode(LinkNode* head)
{
    LinkNode* cur=head;
    while (cur!=nullptr)
    {
        cout << cur->val <<" ";
        cur=cur->next;
    }
    cout << endl;
}

void insert_LinkNode(LinkNode* head,int a)
{
    LinkNode* cur=head;
    if (a<head->val)
    {
        LinkNode* temp=new LinkNode(a);
        temp->next=head;
        head=temp;
        return;
    }
    else
    {
        while (cur->next->val<a && cur->next!=nullptr)
            cur=cur->next;
        LinkNode* temp=cur->next;
        cur->next=new LinkNode(a);
        cur->next->next=temp;
    }
}

int main()
{
    int data[]={1,3,5,7,9,10};
    int a=6;
    LinkNode* head=initial_llink(data,sizeof(data)/sizeof(int));
    insert_LinkNode(head,a);
    print_LinkNode(head);
}
