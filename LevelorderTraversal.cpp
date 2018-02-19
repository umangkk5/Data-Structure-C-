//To determine the level traversal of a binary search tree using BFs technique. This is an iterative method
struct node{
    int data;
    node* left;
    node* right;
}
void levelOrder(node * root) {
    if(root == nullptr)
      return;
    vector<node*> queue;
    queue.push_back(root);
    //cout<<queue[0]->data;
    node* p=root;
    vector<node*>::iterator it=queue.begin();
    
    
    while(!queue.empty())
    {
        node* k= queue.front();
        
        cout<<k->data<<" ";
        queue.erase(queue.begin());    
        
        if(k->left!=nullptr)
        
        {
            queue.push_back(k->left);
                  
        }
        
        if(k->right!=nullptr)
        {
        queue.push_back(k->right);
            
        }
        
    }