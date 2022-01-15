//============================================================================
// Name        : binary.cpp
// Author      : shelke
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include<string.h>
using namespace std;
class tNode                 //node class is created
{
	tNode *Left,*Right;
		char Data[30];


public:

	tNode(char* n)           //parametrised constructor
	{
	strcpy(Data,n);
	Left=Right=NULL;
	}
	void setData(char name[30])
	{
		strcpy(Data,name);
	}
	char* getData()
	{
		return Data;
	}
	tNode *getLeft()
	{
		return Left;
	}
	void setLeft(tNode *p)
	{
		Left=p;
	}
	tNode *getRight()
	{
		return Right;
	}
	void setRight(tNode *p)
	{
		Right=p;
	}

};

class bTree
{
	tNode *Root;
public:
	bTree()
{
		Root=NULL;
}
	void create();
	void insert(char x[]);
	void postorder(tNode* Root);
	void postorder1()
	{
		postorder(Root);
	}
	void preorder_nonrec();
	void inorder_nonrec();
};
class stack1
{

public:

	tNode* st_array[30];
	int top;
	stack1()
	{
		top=-1;
	}
	int empty()
	{
		if(top==-1)
			return 1;
		return 0;
	}
    void push(tNode* p)
    {
    	st_array[++top]=p;
    }
    tNode* pop()
    {
    	return (st_array[top--]);
    }

};
void bTree:: create()
{
	int n;
	char x[30];
	cout<<"\n How many nodes you want to insert in Binary Tree :";
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cout<<"\n Enter Data to Insert:";
		cin>>x;
		insert(x);
	}
}
void bTree::insert(char* x)
{
	tNode *temp;
	char direction;
	int flag=0;
	if(Root==NULL)
	{
		Root=new tNode(x);
		flag=1;
		cout<<"\n Root node is created with data "<<Root->getData();
	}
	else
	{
		temp=Root;
		do
		{
			cout<<"\n Where to add the node(l/r) of"<<temp->getData();
			cin>>direction;
			if(direction=='l')
			{
				if(temp->getLeft()!=NULL)
				{
					temp=temp->getLeft();
				}
				else
				{

					cout<<"\n  left child of "<<temp->getData()<<" is "<<x;
					temp->setLeft(new tNode(x));
					flag=1;
				}
			}
			else
			{
				if(temp->getRight()!=NULL)
					{
						temp=temp->getRight();
					}
					else
					{
						temp->setRight(new tNode(x));
						cout<<"\n Right child of "<<temp->getData()<<" is "<<x;
						flag=1;
					}
			}
			}while(flag==0);

	}

}
void bTree::preorder_nonrec( )
{
  stack1 s;
  tNode* temp;
  s.push(Root);
  while (!s.empty() )
    {
      temp=s.pop();
      if (temp!=NULL )
       {
        cout<<"\t"<<temp->getData();
        s.push(temp->getRight());
        s. push(temp->getLeft());
      }
    }
}


void bTree::inorder_nonrec( )
{
  stack1 s;
  tNode* temp=Root;

  while (! s.empty() || temp!=NULL )
    {
      if( temp!=NULL)
       {
         s.push(temp);
         temp=temp->getLeft();
      }
      else
      {
       temp=s.pop();
       cout<<"\t"<<temp->getData();
       temp=temp->getRight();
       }
     }
  }

void bTree::postorder(tNode *root)
{
	if(root!=NULL)
	{

		   postorder(root->getLeft());
		   postorder(root->getRight());
		   cout<<"\t"<<root->getData();


	}
}
int  main()
{
bTree bt;
char x[30];
int ch;
do
{
cout<<"\n Enter your choice:\t1.create\t 2.insert\t 3postorder\n 4.preorder_nonrec\t5.inorder\t 6.post_nonrec\n:";
cin>>ch;
switch(ch)
{
case 1:
	bt.create();
	break;
case 2:
	cin>>x;
	bt.insert(x);
	break;
case 3:
	bt.postorder1();
    break;
case 4:bt.preorder_nonrec();
break;
case 5:bt.inorder_nonrec();
break;
}
}while(ch!=5);
return 0;
}

/* Enter your choice:	1.create	 2.insert	 3postorder
 4.preorder_nonrec	5.inorder:1

 How many nodes you want to insert in Binary Tree :20

 Enter Data to Insert:DS

 Root node is created with data DS
 Enter Data to Insert:tree

 Where to add the node(l/r) ofDSl

  left child of DS is tree
 Enter Data to Insert:BST

 Where to add the node(l/r) ofDSl

 Where to add the node(l/r) oftreel

  left child of tree is BST
 Enter Data to Insert:TBT

 Where to add the node(l/r) ofDSl

 Where to add the node(l/r) oftreel

 Where to add the node(l/r) ofBSTr

 Right child of BST is TBT
 Enter Data to Insert:BT

 Where to add the node(l/r) ofDSl

 Where to add the node(l/r) oftreel

 Where to add the node(l/r) ofBSTr

 Where to add the node(l/r) ofTBTr

 Right child of TBT is BT
 Enter Data to Insert:Graph

 Where to add the node(l/r) ofDSl

 Where to add the node(l/r) oftreer

 Right child of tree is Graph
 Enter Data to Insert:Dijistra

 Where to add the node(l/r) ofDSl

 Where to add the node(l/r) oftreer

 Where to add the node(l/r) ofGraphl

  left child of Graph is Dijistra
 Enter Data to Insert:kruscal

 Where to add the node(l/r) ofDSl

 Where to add the node(l/r) oftreer

 Where to add the node(l/r) ofGraphl

 Where to add the node(l/r) ofDijistrar

 Right child of Dijistra is kruscal
 Enter Data to Insert:prims

 Where to add the node(l/r) ofDSl

 Where to add the node(l/r) oftreer

 Where to add the node(l/r) ofGraphl

 Where to add the node(l/r) ofDijistrar

 Where to add the node(l/r) ofkruscalr

 Right child of kruscal is prims
 Enter Data to Insert:TPO

 Where to add the node(l/r) ofDSl

 Where to add the node(l/r) oftreer

 Where to add the node(l/r) ofGraphl

 Where to add the node(l/r) ofDijistrar

 Where to add the node(l/r) ofkruscalr

 Where to add the node(l/r) ofprimsr

 Right child of prims is TPO
 Enter Data to Insert:Hash

 Where to add the node(l/r) ofDSl

 Where to add the node(l/r) oftreer

 Where to add the node(l/r) ofGraphr

 Right child of Graph is Hash
 Enter Data to Insert:Search

 Where to add the node(l/r) ofDSl

 Where to add the node(l/r) oftreer

 Where to add the node(l/r) ofGraphr

 Where to add the node(l/r) ofHashr

 Right child of Hash is Search
 Enter Data to Insert:OPBST

 Where to add the node(l/r) ofDSl

 Where to add the node(l/r) oftreer

 Where to add the node(l/r) ofGraphr

 Where to add the node(l/r) ofHashr

 Where to add the node(l/r) ofSearchl

  left child of Search is OPBST
 Enter Data to Insert:AVL

 Where to add the node(l/r) ofDSl

 Where to add the node(l/r) oftreer

 Where to add the node(l/r) ofGraphr

 Where to add the node(l/r) ofHashr

 Where to add the node(l/r) ofSearchl

 Where to add the node(l/r) ofOPBSTr

 Right child of OPBST is AVL
 Enter Data to Insert:Indexing

 Where to add the node(l/r) ofDSl

 Where to add the node(l/r) oftreer

 Where to add the node(l/r) ofGraphr

 Where to add the node(l/r) ofHashr

 Where to add the node(l/r) ofSearchr

 Right child of Search is Indexing
 Enter Data to Insert:B+Tree

 Where to add the node(l/r) ofDSl

 Where to add the node(l/r) oftreer

 Where to add the node(l/r) ofGraphr

 Where to add the node(l/r) ofHashr

 Where to add the node(l/r) ofSearchr

 Where to add the node(l/r) ofIndexingl

  left child of Indexing is B+Tree
 Enter Data to Insert:B_Tree

 Where to add the node(l/r) ofDSl

 Where to add the node(l/r) oftreer

 Where to add the node(l/r) ofGraphr

 Where to add the node(l/r) ofHashr

 Where to add the node(l/r) ofSearchr

 Where to add the node(l/r) ofIndexingl

 Where to add the node(l/r) ofB+Treer

 Right child of B+Tree is B_Tree
 Enter Data to Insert:File

 Where to add the node(l/r) ofDSl

 Where to add the node(l/r) oftreer

 Where to add the node(l/r) ofGraphr

 Where to add the node(l/r) ofHashr

 Where to add the node(l/r) ofSearchr

 Where to add the node(l/r) ofIndexingr

 Right child of Indexing is File
 Enter Data to Insert:DA

 Where to add the node(l/r) ofDSl

 Where to add the node(l/r) oftreer

 Where to add the node(l/r) ofGraphr

 Where to add the node(l/r) ofHashr

 Where to add the node(l/r) ofSearchr

 Where to add the node(l/r) ofIndexingr

 Where to add the node(l/r) ofFilel

  left child of File is DA
 Enter Data to Insert:IA

 Where to add the node(l/r) ofDSl

 Where to add the node(l/r) oftreer

 Where to add the node(l/r) ofGraphr

 Where to add the node(l/r) ofHashr

 Where to add the node(l/r) ofSearchr

 Where to add the node(l/r) ofIndexingr

 Where to add the node(l/r) ofFilel

 Where to add the node(l/r) ofDAr

 Right child of DA is IA
 Enter your choice:	1.create	 2.insert	 3postorder
 4.preorder_nonrec	5.inorder:3
	BT	TBT	BST	TPO	prims	kruscal	Dijistra	AVL	OPBST	B_Tree	B+Tree	IA	DA	File	Indexing	Search	Hash	Graph	tree	DS
 Enter your choice:	1.create	 2.insert	 3postorder
 4.preorder_nonrec	5.inorder:4
	DS	tree	BST	TBT	BT	Graph	Dijistra	kruscal	prims	TPO	Hash	Search	OPBST	AVL	Indexing	B+Tree	B_Tree	File	DA	IA
 Enter your choice:	1.create	 2.insert	 3postorder
 4.preorder_nonrec	5.inorder:5
	BST	TBT	BT	tree	Dijistra	kruscal	prims	TPO	Graph	Hash	OPBST	AVL	Search	B+Tree	B_Tree	Indexing	DA	IA	File	DS
*/
