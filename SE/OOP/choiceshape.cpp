#include<iostream>
#include<math.h>
using namespace std;

int main()
{
 float r,b,c,h,l,a,area;
 int i;
 cout<<"Enter 1 for circle\n"<<"Enter 2 for square\n"<<"Enter 3 for rectangle\n"<<"Enter 4 for triangle\n";
 cin>>i;
 switch (i)
   {
  
   case 1:{cout<<"enter the radius";
         cin>>r;
         area=3.14*r*r;
         break;}
   case 2:{cout<<"enter side";
         cin>>a;
         area=a*a;
         break;}
   case 3:{cout<<"enter length and breadth";
         cin>>b>>c;
         area=l*b;
         break;}
   case 4:{cout<<"enter height and base";
         cin>>h>>b;
         area=(h*b)/2;break;}
         
  default:cout<<"Wrong choice";break;}
 cout<<area;
 return 0;
}


 

         

    

