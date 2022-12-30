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
//building tree using in-order and pre-order traversals
node* buildTree(int in[], int pre[], int inStrt, int inEnd)
{
	static int preIndex = 0;

	if (inStrt > inEnd)
		return NULL;
	node* tNode = newNode(pre[preIndex++]);

	if (inStrt == inEnd)
		return tNode;

	int inIndex = search(in, inStrt, inEnd, tNode->data);
	tNode->left = buildTree(in, pre, inStrt, inIndex - 1);
	tNode->right = buildTree(in, pre, inIndex + 1, inEnd);
	return tNode;
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
	int in[] = {4,2,5,1,6,3};
	int pre[] = {1,2,4,5,3,6};
	int len = sizeof(in) / sizeof(in[0]);
	node* root = buildTree(in, pre, 0, len - 1);
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