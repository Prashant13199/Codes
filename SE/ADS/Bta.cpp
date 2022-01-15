#include<iostream>
#define MAX 80
using namespace std;

class stack
 {
 	int top;
 	int s[MAX];
 	
 	public:
 		stack()
 		 {
 		 	top=-1;
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
	}
	void display()
	{   int i;
		if(isempty())
		cout<<"Empty";
		else
		{
		
		for(i=top;i>=0;i--)
		 {
		 	cout<<s[i];
		 }
	}
	}
 };
 int main()
 {  int d,e;
 	stack n;
 	cout<<"Enter the number";
 	cin>>d;
 	while(d!=0)
 	  {
 	 	e=d%2;
 	 	d=d/2;
 	 	n.push(e);
 	 	
	  }
 	
 	
 	n.display();
 	return 0;
 }
