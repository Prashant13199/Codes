#include<iostream>
#include<string.h>
using namespace std;

class publication
 {
  protected:
  char title[20];
  float price;
 };
 
class book:public publication
 {
  public:
  int pg;
  void setdata(char t[20],float x,int p)
   {
    strcpy(title,t);
    price=x;
    pg=p;
    
   }
   
  void display()
   {
    cout<<"\nTitle of book:"<<title<<endl;
    cout<<"\nPrice of book:"<<price<<endl;
    cout<<"\nNumber of pages:"<<pg<<endl;
   }
 };
 
class tape:public publication
 {
  public:
  int min;
  void setdata(char t[20],float x,int m)
   {
    strcpy(title,t);
    price=x;
    min=m;
   }
   
  void display()
  {
   cout<<"\nTitle of tape:"<<title<<endl;
   cout<<"\nPrice of tape:"<<price<<endl;
   cout<<"\nPlay time:"<<min<<endl;
  }
 };
   
int main()
 {
  char t[20];
  float x;
  int p,z,m,o;
  book b;
  tape s;
  
  
  do{
  cout<<"\nEnter 1 for book:";
  cout<<"\nEnter 2 for tape:";
  cin>>z;
  
  switch(z)
   {
    case 1:  {
           
           cin.ignore();
           cout<<"\nEnter title of book or tape:"<<endl;
  cin.getline(t,20);
  cout<<"\nEnter price of book or tape:"<<endl;
  cin>>x;
   	   cout<<"Enter total pages in book:"<<endl;
  	   cin>>p;
  	   
           try
            {
               if(p<=0)
                {
   	          throw p;
                 }
              else
               { b.setdata(t,x,p);
                  b.display();
                }
            }
        catch(int i)
        {
        cout<<"Exception caught";
        b.setdata("zero",0,0);
        b.display();
       } break;}
   case 2:{
           
           cin.ignore();
           cout<<"\nEnter title of book or tape:"<<endl;
  cin.getline(t,20);
  cout<<"\nEnter price of book or tape:"<<endl;
  cin>>x;
   	   cout<<"Enter play time"<<endl;
  	   cin>>m;
  	   
           try
            {
               if(m<=0)
                {
   	          throw m;
                 }
              else
               { s.setdata(t,x,m);
                  s.display();
                }
            }
        catch(int j)
        {
        cout<<"Exception caught";
        s.setdata("zero",0,0);
        s.display();
       }
       }
   }
   cout<<"if you want to continue press 1";
   cin>>o;
   }
   while(o==1);
   return 0; 
 
  
 }
     
  
