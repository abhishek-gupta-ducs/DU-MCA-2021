#include <bits/stdc++.h>
using namespace std;
class node
{
	public:
	int data;
	node* left;
	node* right;
};
node* newNode(int data)
{
	node* Node = new node();
	Node->data = data;
	Node->left = NULL;
	Node->right = NULL;
	return (Node);
}
int search(int arr[], int strt, int end, char value)
{
	int i;
	for (i = strt; i <= end; i++)
	{
		if (arr[i] == value)
			return i;
	}
    return -1;
}
//building tree using in-order and post-order traversals
node* buildTree(int in[], int post[], int inStrt,int inEnd, int* pIndex)
{
	if (inStrt > inEnd)
		return NULL;
	node* node = newNode(post[*pIndex]);
	(*pIndex)--;
	if (inStrt == inEnd)
		return node;
	int iIndex = search(in, inStrt, inEnd, node->data);
	node->right = buildTree(in, post, iIndex + 1, inEnd, pIndex);
	node->left = buildTree(in, post, inStrt, iIndex - 1, pIndex);
	return node;
}
void pre_order(struct node *temp)
{
    if (temp != NULL)
    {
        cout << " " << temp->data;
        pre_order(temp->left);
        pre_order(temp->right);
    }
}
void in_order(struct node *temp)
{
    if (temp != NULL)
    {
        in_order(temp->left);
        cout << " " << temp->data;
        in_order(temp->right);
    }
}
void post_order(struct node *temp)
{
    if (temp != NULL)
    {
        post_order(temp->left);
        post_order(temp->right);
        cout << " " << temp->data;
    }
}
// Driver code
int main()
{
    int in[] = { 4, 8, 2, 5, 1, 6, 3, 7 };
	int post[] = { 8, 4, 5, 2, 6, 7, 3, 1 };
	int len = sizeof(in) / sizeof(in[0]);
    int pIndex = len - 1;
	node* root = buildTree(in, post, 0, len - 1,&pIndex);
    cout << "Preorder traversal of the constructed tree is \n";
	pre_order(root);
    cout<<endl;
    cout << "Inorder traversal of the constructed tree is \n";
	in_order(root);
    cout<<endl;
    cout << "Postorder traversal of the constructed tree is \n";
	post_order(root);
    cout<<endl;
}