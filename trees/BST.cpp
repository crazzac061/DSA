#include<bits/stdc++.h>
using namespace std;

struct tree
{
    int data;
    tree *left, *right ;
};

tree *createnode(int val)
{
   tree *newnode= new tree();
   newnode->data=val;
   newnode->left=nullptr;
   newnode->right=nullptr;
   return newnode;

}

void insert(tree *&root, int val)
{
    tree *newnode= createnode(val);
    if (root==nullptr)
    {
        root=newnode;
        return;
    }
    if (root->data>val)
    {
        insert(root->left,val);
    }
    else
    {
        insert(root->right,val);
    }
} 

void inorder(tree *&root)
{
    if (root==nullptr)
    {
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
  
}
void preorder(tree *&root)
{
    if (root==nullptr)
    {
        return;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
    
}

int main()
{
    tree *tree=nullptr;

    insert(tree,2);
    insert(tree,9);
    insert(tree,5);
    insert(tree,3);

    inorder(tree);
    cout<<endl;
    preorder(tree);
    return 0;
}