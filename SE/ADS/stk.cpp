#include<iostream>
#include<string.h>
#include<ctype.h>
using namespace std;

class node
        {
        private:
                int data;
                char a[20];

        public:
                node *next;

        void setdata(int d)
                {
                data=d;
                }

        int getdata()
                {
                return data;
                }

        node()
                {
                data='\0';
                next=NULL;
                }

        void setnext(node *n)
                {
                next=n;
                }

        node *getnext()
                {
                return next;
                }

        };

class stack
{
char a[20];
private:
node *start;
int top,data,temp;

public:
stack()
        {
        start=NULL;
        top=-1;
        }

void push(char a]20])
        {
        node *pnew, *ptemp;
        pnew=new node();
        top++;
        pnew->setdata(a[20]);
        if(start==NULL && top<0)
                {
                pnew->next=start;
                start=pnew;
                }
        else
                {
                pnew->next=start;
                start=pnew;
                cout<<top<<max;
                if(top>=max)
                cout<<"stack overflow(full)...";
                }
                pnew->setnext(start);
                start=pnew;
        }

int full()
        {
        if(top==max)
        return 1;
        else
        return 0;
        }

int empty()
        {
        if(top==1)
        return 1;
        else
        return 0;
        }

int pop()
        {
        node*c;
        if(empty())
                {
                cout<<"List is EMPTY.....";
                }
                else
                {
                temp=start->getdata();
                c=start;
                start=start->getnext();
                delete(c);
                return temp;
                }
        }

void display()
{
node *temp, *start;
temp=start;
if(empty())
        {
        cout<<"\nStack is FULL.....";
        }
else
        {
        cout<<"\nCharacters in stack are:";
        }
        while(temp!=NULL)
        {
        if(temp->getdata()==NULL)
        {
        cout<<temp->getdata()<<" ";
        }
        else
        {
        cout<<temp->getdata()<<" ";
        }
        temp=temp->getnext();
        }
}

int priority(char ch)
{
switch(ch)
        {
        case'*':
        case'/':
                return 2;
                break;
        case'+':
        case'-':
                return 1;
                break;
        default:
                return 0;
        }
}

int isoperator(char c)
{
if(c=='+' || c=='-' || c=='*' || c=='/')
return 1;
else
return 0;
}

};
int main()
{
stack s;
int opt;
char ch;
char b[20],a[20];

cout<<"";
}
