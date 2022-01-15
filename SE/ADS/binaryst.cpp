#include<iostream>
using namespace std;
class bstnode
 {
   int data;
   bstnode *left;
   bstnode *right;
   
   public:
   
    bstnode(int x)
     {
          data=x;
          left=NULL;
          right=NULL;
     }
    
    int getdata()
     {
          return data;
     }
    
    bstnode *getleft()
     {
          return left;
     }
     
    bstnode *getright()
     {
          return right;
     }
    
    void setleft(bstnode *l)
     {
         left=l;
     }
    
    void setright(bstnode *r)
     {
         right=r;
     }
 };

class bst
 {
   bstnode *root;
   public:
    bst()
     {
        root=NULL;
     }
   
   void insert(int x)
    {
     
       bstnode *newnode;
       newnode = new bstnode(x);       
       bstnode *temp;
       
       if(root==NULL)
        {
           root=newnode;
        }
        
       else
        {
           temp=root;
           
           do
             {
               if(x<temp->getdata())
                {
                   if(temp->getleft()==NULL)
                    {
                       temp->setleft(newnode);
                       break;
                    }
                   else
                    {
                       temp=temp->getleft();
                    }
                }
               else if(x>temp->getdata())
                 {
                   if(temp->getright()==NULL)
                    {
                       temp->setright(newnode);
                       break;
                    }
                   else
                    {
                       temp=temp->getright();
                    }
                 }
               else
                 {
                     cout<<"Duplicate number entered";
                 }
             }while(temp!=NULL);
        }      
    } 

     void mindata()
      {
	bstnode *temp;
	temp = root;

	if(root == NULL)
	{
		cout<<"\nBST is empty";
	}
	else
	{
		while(temp->getleft() != NULL )
			temp = temp->getleft();

			cout<<"\n Minimum data in BST is : "<<temp->getdata();
	}
     }
    void maxdata()
     {
	bstnode *temp;
	temp = root;

	if(root == NULL)
	{
		cout<<"\nBST is empty";
	}
	else
	{
		while(temp->getright() != NULL)
			temp = temp->getright();

			cout<<"\n Maximum data in BST is : "<<temp->getdata();
	}
     }
      void search()
       {  
          int d;
          cout<<"\nEnter the data you want to search";
          cin>>d;
          bstnode *temp;
          temp=root;
          int flag=0;
          
            if(temp==NULL)
              {
                 cout<<"Tree is empty";
              }
            else if(temp->getdata()==d)
             {
               cout<<"Data found";
             }
            else
              {
                while(temp!=NULL)
                  
                   {
                   
                     if(temp->getdata()==d)
                       {
                         flag=1;
                         break;
                       }
                     else if(temp->getdata()>d)
                       {
                         temp=temp->getleft();
                       }
                     else if(temp->getdata()<d)
                       {
                         temp=temp->getright();
                       }
               }
                  
                  
                if(flag == 1)
			cout<<"\nData found";
		else
			cout<<"\nData not found";
             }
           }
       
 
        
      void display()
       {
                cout<<"\n Inorder display of binary tree : ";
                inorder(root);
              
                
       }
      
      void display2()
        {       image(root);
                cout<<"\n Inorder display of binary tree : ";
                inorder(root);
              
                
       }
       
     

               
       
     void inorder(bstnode *root)
       {
          if(root!=NULL)
           {
               inorder(root->getleft());
               cout<<root->getdata()<<" ";
               inorder(root->getright());
           }
       }
    
    void image(bstnode *root)
     {
	bstnode *temp;
	if(root != NULL)
	{
		temp = root->getleft();
		root->setleft(root->getright());
		root->setright(temp);
		image(root->getleft());
		image(root->getright());
		
	}
     }
    int max(int a,int b)
      {
        if(a>b)
         {
          return a;
         }
        else
         {
           return b;
         }
      }
    
     void h()
      {  
        cout<<"Height :"<<height(root);
      }
     
     int height(bstnode *root)
      {
        bstnode *temp;
        temp=root;
          if(root==NULL)
           {
             return 0;
           }
         if(temp->getleft()==NULL && temp->getright()==NULL)
           {
              return 1;
           }                
             return 1+max(height(temp->getleft()),height(temp->getright()));
      }
      
             
 };
 
 int main()
   {
     bst b;
     b.insert(2);
     b.insert(1);
     b.insert(3);
     b.insert(4);
     b.mindata();
     b.maxdata();
     b.search();
     b.display();
     b.display2();
     b.h();
     
    
    
    
    
     return 0;
   }                                 
     
     
    
    
   
   
