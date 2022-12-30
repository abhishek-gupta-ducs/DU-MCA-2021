#include<bits/stdc++.h>
using namespace std;
class Node{
       public:
    int data;
 
    Node* left;
    Node* right;
Node(int d){
    data=d;
    left=right=NULL;
}
};
class BinarySearchTree{
    public:
    Node* root=NULL;
    void insert(int d){
        Node* temp=root;
        Node* prev_temp=NULL;
        while(temp!=NULL){
            prev_temp=temp;
            if(d<temp->data){
                temp=temp->left;
            }
            else{
                temp=temp->right;
            }
        }
        if(prev_temp==NULL)
        {
            root=new Node(d);
            return;
        }
        
        else if(d<prev_temp->data){
            Node* newNode =new Node(d);
            prev_temp->left=newNode;
        }
        else{
            Node* newNode =new Node(d);
            prev_temp->right=newNode;
        }
    }
    // Preorder Traversal
    void pre_order(Node *temp)
    {
        if (temp != NULL)
        {
            cout << " " << temp->data;
            pre_order(temp->left);
            pre_order(temp->right);
        }
    }
    // Inorder Traversal
    void in_order(Node *temp)
    {
        if (temp != NULL)
        {
            in_order(temp->left);
            cout << " " << temp->data;
            in_order(temp->right);
        }   
    }

// Traverse Postorder
    void post_order(Node *temp)
    {
        if (temp != NULL)
        {
            post_order(temp->left);
            post_order(temp->right);
            cout << " " << temp->data;
    }
    }
    };

int main(){
    BinarySearchTree b;
    //while(true){
    b.insert(10);
    b.insert(12);
    b.insert(5);
    b.insert(4);
    b.in_order(b.root);
}
