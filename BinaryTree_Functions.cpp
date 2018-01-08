#include <iostream>

using namespace std;

class Node{
    public:
  int data;
  Node *left;
  Node *right;
  
  Node(int d)
  {
      data = d;
  }
};
class Binarytree{
    public:
  Node *root;
  
  void insert(int d)
  {
      Node *t = new Node(d);
      if(root == NULL)
      {
          t->left = NULL;
          t->right = NULL;
          root = t;
      }
      else
      {
          Node *p;
          p=root;
          while(p){
              if(p->data > d)
              {
                  if(p->left !=NULL)
                  p= p->left;
                  else
                  break;
              }
              else{
                  if(p->right!=NULL)
                  p=p->right;
                  else
                  break;
              }
              
          }
          if(p->data < d)
          p->right = t;
          else
          p->left= t;
      }
      
  }
  void preorder(Node *p){
      if(p == NULL)
      return;
      
      cout<<p->data;
      preorder(p->left);
      preorder(p->right);
  }
  
  void postorder(Node *p){
      if(p == NULL)
      return;
      
      postorder(p->left);
      postorder(p->right);
      cout<<p->data;
  }
  
  void inorder(Node *p){
      if(p == NULL)
      return;
      
      inorder(p->left);
      cout<<p->data;
      inorder(p->right);
      
  }
  bool BSTcheck(Node* p,int min,int max )
  {
      
      if(p == NULL)
      return false;
      
    if(p->data > min && p->data < max )
    return true;
    
    return 
    (BSTcheck(root->left,min,p->data-1) && 
    BSTcheck(root->right,p->data+1,max));
    
    
    
  }
  bool BSTvalid()
  {
      bool check =true ;
      check = BSTcheck(root,0,1000);
      return check;
  }
  void display()
  {
      cout<<"PreOrder Traversal:";
      preorder(root);
      cout<<endl<<"inOrder Traversal:";
      inorder(root);
      cout<<endl<<"PostOrder Traversal:";
      postorder(root);
  }
  
};
int main()
{
    Binarytree tree;
    tree.insert(90);
    tree.insert(1);
    tree.insert(9);
    tree.insert(13);
	tree.insert(16);
	tree.insert(3);
	tree.display(37);
    bool value =true;
    value= tree.BSTvalid();
    if(value)
		cout<<"Valid BST: "<<"Yes";
	else
		cout<<"Valid BST:"<<False;
   
   return 0;
}