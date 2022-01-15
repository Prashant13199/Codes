#include<iostream>
#include<string.h>
using namespace std;

class student
 {
  int prn;
  char name[30];
  student *next;
  public:
   student(int x,char a[30])
    {
     prn=x;
     strcpy(name,a);
     next=NULL;
    }
    
  int getprn()
   {
    return prn;
   }
   
  char* getname()
   {
    return name;
   }
   
  student* getnext()
   {
    return next;
   }
   
  void setnext(student *n)
   {
    next=n;
   }

   
 };  
 
class pinnacle_club
 {
  int x; char a[30];
  student *president;
  student *secretary;
  
  public:
  
   pinnacle_club()
    {
     president=NULL;
     secretary=NULL;
    }
    
  void create();
  void display();
 };
    
  void pinnacle_club::create()
   { 
    student *nn,*temp;
    int ans;
    do
    {
    cout<<"Enter name";
    cin>>a;
    cout<<"Enter prn number";
    cin>>x;
    nn = new student(x,a);
   
    if(president==NULL)
     {
       president=nn;
       secretary=nn;
     }
   else
    { temp=president;
       while(temp->getnext()!=NULL)
        {
	     temp=temp->getnext();
        }
	temp->setnext(nn);
	secretary=nn;
    }
    cout<<"do you wamt to add new member..(press 1)";
    cin>>ans;
    }while(ans==1);
  }

void pinnacle_club::display()
 {
  student *temp;
  temp=president;
  while(temp!=NULL)
   {
    cout<<temp->getprn()<<" "<<temp->getname()<<"\n";
    temp=temp->getnext();
   }
 }
 
int main()
 {
  pinnacle_club s;
  s.create();
  s.display();
  return 0;
 }

  
    
