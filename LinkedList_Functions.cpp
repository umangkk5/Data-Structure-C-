#include <iostream>

using namespace std;
class Node{
    public:
    int data;
    Node *next;
    
    Node(int d)
    {
        data = d;
        
    }
};
class list{
    public:
    Node* head;
    
    
    void insertlast(int data){
        if(head == NULL)
        {
            Node* newnode = new Node(data);
            newnode->next = NULL;
            head = newnode;
           
            return;
        }
        else
        {
        Node *p;
        p=head;
        for(int i=0;p->next != NULL; p = p->next)
        i++;
        
        Node *newnode = new Node(data);
        p->next = newnode;
        newnode->next = NULL;
       
        }
    }
    
    void deletenode(int position)
    {
        if(head == NULL)
        return;
        
        if(position == 0)
        {
            Node *p= head;
            if(head->next == NULL)
            {
                head = NULL;
            }
            else
            {
            head = head->next;
            delete p;
            }
        }
        else{
            Node *p ,*q;
            p= head;
            for(int i=0;i<position; i++)
            {
            q = p;    
            p = p->next;
            }
            
            q->next = p->next;
            delete p;
        }
    }
    
    void display()
    {
        Node *p;
        p=head;
        cout<<endl;
        while(p !=  NULL)
        {
            cout<< p->data;
            p = p->next;
        }
        
    }
    
    void insertf(int position,int data)
    {
        if(head == NULL)
        return;
        
        if(position == 0)
        {
            Node *newnode = new Node(data);
            newnode->next  = head ;
            head = newnode;
        }
        else
        {
        Node *p,*q;
        p=head;
        
        for(int i=0;i<position;i++)
        {
        q=p;
        p = p->next;
        }
        Node *newnode = new Node(data);
        newnode->next = p;
        q->next = newnode;
        }
        
     }
     
     void reverselist()
     {
         if(head == NULL)
         return;
         Node *curr = head;
         Node *prev,*adv; 
         while(curr!= NULL)
         {
            adv = curr->next;
            curr->next = prev;
            prev = curr;
            curr = adv;
         }
     }
};
int main()
{
   cout << "Hello World" << endl; 
   list one;
   
   one.insertlast(20);
   one.insertlast(40);
   one.insertlast(60);
   one.display();
   one.insertf(1,55);
   one.insertf(0,95);
   one.display();
   one.deletenode(2);
   one.deletenode(0);
   one.display();
   //one.insertlast(one,)
   return 0;
}