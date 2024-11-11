#include<iostream>
using namespace std;

struct LinkNode
{
    int val;
    LinkNode* next;
    LinkNode(int a):val(a),next(nullptr){};
};

LinkNode* initialLink(int data[],int len)
{
    if (len<=0)
        return nullptr;
    LinkNode *head=new LinkNode(data[0]);
    LinkNode *cur=head;
    for (int i=1;i<len;i++)
    {
        cur->next=new LinkNode(data[i]);
        cur=cur->next;
    }
    return head;
}

LinkNode* reverseLink(LinkNode* head)
{
    if (head==nullptr || head->next==nullptr)
        return head;
    LinkNode* cur=head;
    LinkNode* pre=nullptr;
    LinkNode* qnext=nullptr;
    while(cur!=nullptr)
    {
        qnext=cur->next;
        cur->next=pre;
        pre=cur;
        cur=qnext;
    }
    head=pre;
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

int main()
{
    int data[]={1,3,4,5,7,9,11,15,98};
    LinkNode* head=initialLink(data,sizeof(data)/sizeof(int));
    outputLink(head);
    head=reverseLink(head);
    outputLink(head);
    return 0;
}
