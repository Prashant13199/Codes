#include<iostream>
#include<string.h>
using namespace std;

class employee
 { 
   int age,veh;char home[30];int sal;
 
    public:
     class myexception
      {
       public:
        char error[30];
         myexception(char s[30])
          {
           strcpy(error,s);
          } 
      };

   void getdata()
   {
     cout<<"\nEnter your age";
     cin>>age;
     if(age<18 || age>55)
      {
       throw myexception("Age not correct");
      }
    cout<<"\nEnter your home city";
    cin>>home;
    if(strcmp("pune",home)==0 || strcmp("mumbai",home)==0 || strcmp("bangalore",home)==0||strcmp("chennai",home)==0)
     {
      
     }
     else throw myexception("\nHome city not correct");
   cout<<"\nEnter your salary:";
   cin>>sal;
   if(sal<50000 || sal>100000)
    {
     throw myexception("\nSalary not correct");
    }
   cout<<"\nType of vehicle:";
   cin>>veh;
   if(veh!=4)
    {
     throw myexception("Vehicle type incorrect");
    }
   }
    
  void display()
   {
    cout<<"\nYour age is:"<<age;
    cout<<"\nYour salary is:"<<sal;
    cout<<"\nYour home city is:"<<home;
    cout<<"\nType of vehicle:"<<veh;
   }
  
 };
   
 int main()
  
  {
    
    employee s;
    while(true)
    
     try{
         s.getdata();
         s.display();
         break;
        }
        
     catch(employee::myexception a)
      {
       cout<<a.error;
      }
      return 0;
  }
  
