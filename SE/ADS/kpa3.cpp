#include<iostream>
using namespace std;

class tbtnode
 {
   int data;
   tbtnode *left,*right;
   int lbit,rbit;
   public:
     
        tbtnode(int x)
          {
            data=x;
            left=NULL;
            right=NULL;
            lbit=1;
            rbit=1;
          }
        
     int getdata()
      {
        return data;
       }
     
     tbtnode *getleft()
      {
        return left;
      }
     
     tbtnode *getright()
      {
        return right;
      }
     
     void setleft(tbtnode *left1)
      {
        left=left1;
      }
     
     void setright(tbtnode *right1)
      {
        right=right1;
      }
    
    int getlbit()
     {
       return lbit;
     }
    
    int getrbit()
     {
       return rbit;
     }
 

    void setlbit(int l)
     {
       lbit=l;
     }
    
    void setrbit(int r)
     {
       rbit=r;
     }
  };

class tbt
 {
   tbtnode *root,*temp;

   public:
    tbt()
     {
       root=NULL;
     }
   
   void insert(int x)
    {
      tbtnode *newnode;
      newnode=new tbtnode(x);
      if(root==NULL)
       {
         root=newnode;
         cout<<"Root created";
       }
      else
       {
         temp=root;
         do
          {
        
           if(x>temp->getdata())
            { 
              if(temp->getrbit()==1)
               {
                 newnode->setleft(temp->getleft());
                 newnode->setright(temp);
                 temp->setright(newnode);
                 temp->setrbit(0);
                 cout<<"Data entered at right"<<temp->getrbit();
                 break;
                 
               }
            
               else
               {
                temp=temp->getright();
               }
             
            }
           else if(x<temp->getdata())
                 {
                   if(temp->getlbit()==1)
                    {
                      newnode->setleft(temp->getleft());
                      newnode->setright(temp);
                      temp->setleft(newnode);
                      temp->setlbit(0);
                      cout<<"Data entered at left"<<temp->getlbit();
                      break;
                    }
                   else
                    {
                      temp=temp->getleft();
                    }
                 }
        }while(temp!=NULL);
     }
   }
 
 };
          
             
            
         
   
         




int main()
 { 
   tbt t;
   t.insert(2);
   t.insert(1);
   t.insert(3);
   
 
   return 0;
 
 }

