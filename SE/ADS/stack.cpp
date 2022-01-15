#include<iostream>
using namespace std;

class node
 {
  int data;
   
   public:
   node(int x)
    {
     data=x;
    }
   void setnext()
    {
     next=n;
    }
   void getdata()
    {
     return data;
    }
   void getnext(node *n)
    {
     next=n;
    }
   
   int isfull()
     {
     	if(top==MAX-1)
     	 return 1;
     	 
     	 else
     	  return 0;
	 }
	int isempty()
	{
		if(top==-1)
		return 1;
		else
		return 0;
	}
	void push(int item)
	{
		if(isfull())
		 cout<<"Stack full";
		 else
		{
		  top++;
		  s[top]=item;
		 }
	}
	void pop()
	{
		if(isempty())
		 cout<<"Stack full";
		 else
		  s[top--];
    
   
 };

class sll
 {
  node *head;
  public:
   sll()
    {
     head=NULL;
    }
  void create();
 }

void sll::create()
 {
  node *head,*temp;
  
  
