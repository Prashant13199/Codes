#include<iostream>
using namespace std;

class node
{
private:

	int data;
	node *left;
	node *right;
public:


		 node(int val)
		{
			data=val;
			left=NULL;
			right=NULL;

		}

		 void setdata(int x)
		 {
			 data=x;

		 }
		 int getdata()
		 {
			 return data;

		 }
		 void setleft(node *lef)
		 {
			 left=lef;

		 }
		 node *getleft()
		 {
			 return left;
         }

		 void setright(node *rig)
		 {
			 right=rig;

		 }
		 node *getright()
		 {
			 return right;

		 }
	};
class tree
{
private:
	node* root;
public:
	tree()
	{
		root=NULL;
	}

public:
	void  create(int n);
	void insert(int val);
    void preorder(node*);
    void inorder(node*);
    void display();
   int find(int target);
    int findmin(node*);
    int findmax(node*);
    void mirror(node*);
   int longestpath(node*);
void operations();
};
void tree::create(int n)
{
	int i=0;int val;
	while(i<n)
	{
		cout<<"which no to insert";
		cin>>val;
		insert(val);
     i++;
	}
}

void tree::insert(int val)
{
 node *pnew;node *temp;
 int insert=0;
 pnew=new node(val);

 if(root==NULL)
 {

	 root=pnew;
	 insert=1;
 }
 else
 {
	 temp=root;
do
{

	if(temp->getdata()>val)
	{
		if(temp->getleft()!=NULL)
		temp=temp->getleft();
       else
	   {

		temp->setleft(pnew);
        insert=1;
	   }
	}
	else if(temp->getdata()<val)
	{
		if(temp->getright()!=NULL)
		{
			temp=temp->getright();

		}
		else
		{
			 temp->setright(pnew);
			 insert=1;
		}
	}
}while(insert==0);
}
}
void tree::inorder(node *temp)
{
	if(temp!=NULL)
	{
		inorder(temp->getleft());
		cout<<temp->getdata();
		inorder(temp->getright());



	}
}

void tree::preorder(node *temp)
{
	if(temp!=NULL)
	{

		cout<<temp->getdata();
		preorder(temp->getleft());
		preorder(temp->getright());

	}
}


int tree::find(int target)
{
int flag=0;
node *temp=root;
while(temp!=NULL)
{
	if(target==temp->getdata())
	{
		cout<<"\n";
		cout<<target<<"\t"<<"is found in binary search tree";
		flag=1;
		break;
	}
	if(target>temp->getdata())
	{
		temp=temp->getright();

	}
	else
	{
		temp=temp->getright();
	}
}
return flag;
}


int tree::findmin(node *root)
{
	node *temp=root;
	if(root!=NULL)
	{
		while(temp->getleft()!=NULL)
		temp=temp->getleft();

	}
	return(temp->getdata());

}

int tree::findmax(node *root)
{
	node *temp=root;
	if(root!=NULL)
	{
		while(temp->getright()!=NULL)
		temp=temp->getright();

	}
	return(temp->getdata());

}
void tree::display()
{
	cout<<"\n";
	preorder(root);
	cout<<"\n";
	inorder(root);


}


void tree::mirror(node *root)
{
	node *temp;
	if(root!=NULL)
	{
		temp=root->getleft();
		root->setleft(root->getright());
		root->setright(temp);
		mirror(root->getleft());
		mirror(root->getright());
cout<<"\n";
	}
	preorder(root);
}

int tree::longestpath(node *temp)
{
    int heightL,heightR;
    if(temp==NULL)
        return 0;
    if(temp->getleft()==NULL && temp->getright()==NULL)
        return 0;
    heightL=longestpath(temp->getleft());
    heightR=longestpath(temp->getright());
    if(heightR>heightL)
        return(heightR+1);
    return(heightL+1);
}

void tree::operations()
{
	int s=findmin(root);
	cout<<"\n";
	cout<<"smallest value in tree is"<<s<<"\n";

	int B=findmax(root);
	cout<<"\n";
	cout<<"greater value of node in tree is"<<B<<"\n";
	cout<<"\n";
	cout<<"mirror image of binary tree is:";
	mirror(root);
	cout<<"\n";
}
int main()
{
	 tree T;
 int n,ch,i=0,val,n1;
 char op;
 int target,flag=0;
 do
	 {
	 cout<<"\n";
		 cout<<"enter your choice::\n";
		 cout<<"1.create\n";
		 cout<<"2.insert\n";
		 cout<<"3.display\n";
		 cout<<"4.search node\n";
		 cout<<"5.operations";
		 cin>>ch;

		 switch(ch)
		 {

		 case 1:
	 cout<<"how many nodes in  your binary tree";
	 cin>>n;
	 T.create(n);
      break;

		 case 2:
			 cout<<"no of elements want to insert";
			 cin>>n1;
while(i<n1)
{
	cout<<"data for element to insert";
	cin>>val;
T.insert(val);
i++;
}
         break;

		 case 3:
			 T.display();
			 break;

		 case 4:
			 cout<<"enter targetkey";
			 cin>>target;
			flag=T.find(target);
			 if(flag==1)
             cout<<"key  is found in binary tree";
			 break;
		 case 5:
			 T.operations();
			 break;


		  }

cout<<"\n";
        cout<<"do you want to continue(y/n)";
			 cin>>op;

}while(op!='n');
		 return (0);
	 }
/*
enter your choice::
1.create
2.insert
3.display
4.search node
5.operations1
how many nodes in  your binary tree4
which no to insert2
which no to insert3
which no to insert1
which no to insert5

do you want to continue(y/n)y

enter your choice::
1.create
2.insert
3.display
4.search node
5.operations3

2135
1235
do you want to continue(y/n)y

enter your choice::
1.create
2.insert
3.display
4.search node
5.operations4
enter targetkey2

2	is found in binary search treekey  is found in binary tree
do you want to continue(y/n)y

enter your choice::
1.create
2.insert
3.display
4.search node
5.operations5

smallest value in tree is1

greater value of node in tree is5

mirror image of binary tree is:
5
35
1
2351

do you want to continue(y/n)*/
