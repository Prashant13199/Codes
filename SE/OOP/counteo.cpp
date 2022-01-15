#include<stdio.h>
#include<iostream>
using namespace std;
int main()
{
 int i,a=0,b=0,n;
cout<<"enter number";
cin>>i;
for(n=0;n<10;n++)
{
 if(i%2==0)
 {
  a=a+n;
 }
else if(i%2!=0)
 {
  b=b+n;
 } }
cout<<"Even number"<<a;
cout<<"odd number"<<b;

return 0;
}






























 
 
