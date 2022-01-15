#include<iostream>
#include<string.h>
#define MAX 19
using namespace std;
class graphnode
{
   public:
           char word[20],meaning[20];
           graphnode *next;
           graphnode(char wd[20],char nm[20])
           {
               strcpy(word,wd);
               strcpy(meaning,nm);
                next=NULL;
              }
};

class graph
{
graphnode *head[20];

public:
	graph()
	{
   for(int i=0;i<20;i++)
      head[i]=NULL;
	}
    int insert1(char[],char[]);
    void display();
};

int graph::insert1(char wd1[20],char mn[20])
{
    string wd;
    string pnew,qnew;
    int x,y;
    wd=wd1;
graphnode *q,*prev,*temp;
q=new graphnode(wd1,mn);
int nm=0,n,index;
    for(int i=0;i<wd.length();i++)
    {
        n=wd[i];
        nm=nm+n;
    }
    index=nm%MAX;
    if(head[index]==NULL)
    head[index]=q;
    else
    {
        prev=head[index];
        temp=prev->next;
        qnew=q->word;
       label:if(prev->next==NULL)
        {
           for(int i=0;i<30;i++)
            {
           pnew=prev->word;
            x=pnew[i];
           y=qnew[i];
           if(x!=y && x>y)
            {
               q->next=prev;
               head[index]=q;
               break;
            }
           else if(x!=y && x<y)
            {
               prev->next=q;
               break;
            }
            }
        }
        else
        {

        	for(int i=0;i<30;i++)
        	 {
        	          pnew=prev->word;
        	            x=pnew[i];
        	           y=qnew[i];
        	           if(x!=y && x>y)
        	            {
        	               q->next=prev;
        	               head[index]=q;
        	               return 1;
        	            }
        	           else if(x!=y && x<y)
        	            {
        	        	   q->next=temp;
        	               prev->next=q;

        	               return 1;
        	            }
        	  }
        	while(temp!=NULL)
        	{

        		for(int i=0;i<30;i++)
        		{
        			pnew=temp->word;
        			x=pnew[i];
        			y=qnew[i];
        			if(x>y)
        			{
        				q->next=temp;
        				prev->next=q;
        			}
        			else
        			{
        				if(temp->next==NULL)
        				{

        					for(int i=0;i<30;i++)
        					{
        						pnew=temp->word;
                	            x=pnew[i];
                	            y=qnew[i];
                	            if(x!=y && x>y)
                	            {
                	               q->next=temp;
                	               prev->next=q;
                	               break;
                	            }
                	           else if(x!=y && x<y)
                	            {
                	        	   temp->next=q;
                	               break;
                	            }
        					}
        				}
        				else
        				{
        					prev=temp;
        					temp=temp->next;

        				}
        			}
        		}
        	}
        }
    }
return 1;
}

void graph::display()
{
    graphnode *temp;
    cout<<"**--------------------------------**"<<endl;
    cout<<"     word          meaning   "<<endl;
    cout<<"**--------------------------------**"<<endl;

    for(int i=0;i<MAX;i++)
	{

		if(head[i]!=NULL)
		{
			temp=head[i];
			while(temp!=NULL)
			{
			cout<<"     "<<temp->word<<"          "<<temp->meaning<<endl;
			temp=temp->next;

			}
			cout<<endl;

		}
	}cout<<endl<<"**--------------------------------**"<<endl;

}

int main()
{
    graph g;
   char name[20],mean[20];
   int n;
    cout<<"How many records you want to insert in dictionary : ";
    cin>>n;
    for(int i=0;i<n;i++)
    {
    cout<<"Enter word and its meaning respectively : ";
    cin>>name>>mean;
    g.insert1(name,mean);
    }
    g.display();
}

