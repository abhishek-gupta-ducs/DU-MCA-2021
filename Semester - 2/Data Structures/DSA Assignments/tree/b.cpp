#include <bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    struct node *left, *right;
};
struct node *newnode(int d)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = d;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}
// Preorder Traversal
void pre_order(struct node *temp)
{
    if (temp != NULL)
    {
        cout << " " << temp->data;
        pre_order(temp->left);
        pre_order(temp->right);
    }
}
// Inorder Traversal
void in_order(struct node *temp)
{
    if (temp != NULL)
    {
        in_order(temp->left);
        cout << " " << temp->data;
        in_order(temp->right);
    }
}

// Traverse Postorder
void post_order(struct node *temp)
{
    if (temp != NULL)
    {
        post_order(temp->left);
        post_order(temp->right);
        cout << " " << temp->data;
    }
}
//main function
int main() {
    struct node *root = newnode(1);
    root->left = newnode(2);
    root->right = newnode(3);
    root->left->left = newnode(4);
    cout << "preorder traversal: ";
    pre_order(root);
    cout << "\nInorder traversal: ";
    in_order(root);
    cout << "\nPostorder traversal: ";
    post_order(root);
    cout<<endl;
}