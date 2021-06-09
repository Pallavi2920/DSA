#include<bits/stdc++.h>
using namespace std;
std::vector<int> v;
struct Node
{
    int data;
    Node *left;
    Node *right;
};
typedef struct Node Node;

Node *create()
{
    Node *newNode = (Node*)malloc(sizeof(Node));
    int x;
    cout<<"Enter the value (-1 for no entry):"<<endl;
    cin>>x;
    if(x==-1) return 0;
    newNode->data = x;
    cout<<"Enter the left child of "<<x<<":";
    newNode->left=create();
    cout<<"Enter the right child of "<<x<<":";
    newNode->right=create();
    return newNode;
}
void dll(Node *root,Node* &head,Node* &prev)
{
    if(root==NULL)  return;
    dll(root->left,head,prev);
    if(prev == NULL)
    {
        head = root;
        prev = root;
    }
    else
    {
        prev->right = root;
        prev->right->left = prev;
        prev = prev->right;
    }
    dll(root->right,head,prev);

}
int main()
{
    std::vector<int> v;
    Node *root = (Node *)malloc(sizeof(Node));
    root = create();
    Node *head = (Node*)malloc(sizeof(Node));
    head = NULL;
    Node *prev = (Node*)malloc(sizeof(Node));
    prev = NULL;
    dll(root,head,prev);
    Node *temp = (Node*)malloc(sizeof(Node));
    temp = head;
    while(temp!=NULL)
    {
        cout<<temp->data<<"<->";
        temp = temp->right;
    }
}
