#include<stdio.h>
#include<iostream>
using namespace std;
int main()
{

int i,n,x,large=0;
cout<<"enter number";
cin>>n;

for(i=1;i<=n;i++)
 {
 cout<<"enter number";
 cin>>x;
 if(x>large)
 large=x;
 }
 cout<<"larger no:"<<large;
return 0;
}
