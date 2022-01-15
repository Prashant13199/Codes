#include<iostream>
#include<queue>
using namespace std;

class node
{
        private:
                int data,rbit;
                node *right;
		node *left;
        public:
                node();

       int getdata();
        void setdata(int val);

        node *getright();
        void setright(node *rLink);

	node *getleft();
        void setleft(node *lLink);

        int getrbit();
                void setrbit(int val);
};


node::node(){
	data = rbit=0;
	left = NULL;
	right=NULL;
}

int node::getdata()
{
	return data;
}

void node::setdata(int val)
{
	data = val;
}

int node::getrbit()
{
	return rbit;
}

void node::setrbit(int val){
	rbit = val;
}

node *node::getright(){
	return right;
}

void node::setright(node *rLink){
	right = rLink;
}

node *node::getleft(){
	return left;
}

void node::setleft(node *lLink){
	left = lLink;
}

class bTree
{
        private:
                node *root,*head;

        public:
		queue <node*> q;
		bTree();
		void create(int count);
		void insert(int value);
		void display();
		void preorder(node *temp);
		void tbtree(node *temp);
		int display1(node *temp);
};

bTree::bTree()
{
	root=head=NULL;
}

void bTree::create(int count)
{
	int i=0;
	int value;
	for(i=0;i<count;i++)
	{
		cout<<"enter the value for node "<<i+1<<" : ";
		cin>>value;
		insert(value);
	}
}

void bTree::insert(int value)
{
	node *pNew,*temp;
	int insert=0;
	char position;
	pNew=new node();
	pNew->setdata(value);

	if(root==NULL)
	{
		head=new node();
		head->setdata(-999);
		root=pNew;
		head->setleft(root);
		insert=1;
	}
	else
	{
		temp=root;
		do
		{
			cout<<"Where you want to insert node (l/r):";
			cin>>position;
		if(position=='l')
		{
			if(temp->getleft()!=NULL)
			{
				temp=temp->getleft();
			}
			else
			{
				temp->setleft(pNew);
				insert=1;
			}
		}
		else
		{
			if(temp->getrbit()!=0)
			{
				temp=temp->getright();
			}
			else
			{

				temp->setright(pNew);
				temp->setrbit(1);
				insert=1;
			}
		}
		}while(insert==0);
	}
}

void bTree::preorder(node *temp)
{
	if(temp!=NULL)
	{
		q.push(temp);
		preorder(temp->getleft());
		preorder(temp->getright());
	}
}

void bTree::tbtree(node *temp)
{

	node *tmp;
	preorder(root);
	node *rr=q.back();q.pop();
	while(!q.empty())
	{
	if(root==NULL)
	{}
	else
	{
		while(temp->getleft()!=NULL)
		{
		temp=q.front();
		q.pop();
		}
		if(temp->getright()!=NULL)
		{
			temp=q.front();
		       q.pop();
		}
		else
		{
			if(temp==rr)
			rr->setright(head);
			else
			{
			tmp=q.front();
			q.pop();
			temp->setright(tmp);
			temp=tmp;
			}
		}
	}
	}
}

int bTree::display1(node *temp)
{
	if(temp!=NULL)
	{
		while(temp!=NULL)
		{
			while(temp->getleft()!=NULL)
			{
				cout<<" "<<temp->getdata();
				temp=temp->getleft();
			}

			if(temp->getrbit()==0)
			{
				if(temp->getright()==head)
				{
					cout<<" "<<temp->getdata();
					return 0;
				}
			}
			cout<<" "<<temp->getdata();
			temp=temp->getright();
		}
	}
	return 1;
}

void bTree::display()
{
	cout<<"Preorder  : ";
	tbtree(root);
	display1(root);
}

int main()
{
	bTree bt;
	int n;
	cout<<"How many nodes you want to insert in binary tree : ";
	cin>>n;
	bt.create(n);
	bt.display();
	return 0;
}
