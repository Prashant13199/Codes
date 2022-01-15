#include<iostream>
using namespace std;

class graphnode
{
   public:
           int vertex;
           graphnode *next;
           graphnode(int vj)
           {
               vertex=vj;
               next=NULL;
           }

};

class graph
{

private:
	int vertex;

int i,j;
int g[20][20],n,edges,visited[20];
char type;

public:
	graphnode *head[20];
        void create();
        void insert(int,int);
        void list(int v);
        void display();
        void insert1(int i,int vi);
        void display1();
        graph()
        {
        	for(int i=0;i<20;i++)
        		head[i]=NULL;
        }
};

void graph::create()
{
     int i,j,vi,vj;
     cout<<"\n Enter No of Vertices : ";
     cin>>n;
      for(i=0; i<n; i++)
	{
		for(j=0;j<n;j++)
		g[i][j]=0;
	}
cout<<"\n Enter D(for directed) || U(for undirected)) ";
 cin>>type;
cout<<"\n Enter No Of Edges: ";
cin>>edges;
for(i=0;i<edges;i++)
{
cout<<"\n Enter Edge(Vi,Vj) : ";
cin>>vi>>vj;
insert(vi,vj);
}
}
void graph:: insert(int vi, int vj)
{

	if(type=='d' || type=='D')
		g[vi][vj]=1;
	else
		g[vi][vj]=g[vj][vi]=1;
}
void graph::insert1(int i,int vj)
{
graphnode *p,*q;
q=new graphnode(vj);
  if(head[i]==NULL)
    head[i]=q;
  else
  {
    p=head[i];
    while(p->next!=NULL)
       p=p->next;
    p->next=q;
   }
}
void graph::display1()
{         int i;
	graphnode *temp;


	for(i=0;i<n;i++)
	{
		temp=head[i];
		cout<<"list is"<<i;
		while(temp!=NULL)
		{
			cout<<i<<"-"<<temp->vertex;
			temp=temp->next;
		}
}
}

void graph::display()
{
	for(int i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
			cout<<g[i][j];
		    cout<<endl;
	}

}


int main()
{
graph g;
int i,vi,vj,ch;
	do
	{
		cout<<"\n 1. Create.\n 2. Insert.\n3.display";
		cout<<"\n Enter Your Choice : ";
		cin>>ch;
		switch(ch)
		{
			case 1:
				g.create();

				    break;
			case 2: cout<<"\n Enter Edge from which vertices( Vi, Vj) :";
				    cin>>vi>>vj;
				    g.init();
				    g.insert(vi,vj);
				    g.insert1(i,vi);
				    break;
			case 3:
				g.display();
				g.display1();
				break;
			default:
				cout<<"wrong choice";
				break;
		}
	}while(ch!=3);
	return 0;
}
