#include<stdio.h>
#include<iostream>
using namespace std;
int main()
{

int i,n,x,large=0;

for(i=1;i<=10;i++)
 {
 cout<<"enter number";
 cin>>x;
 if(x>large)
 large=x;
 }
 cout<<"larger no:"<<large;
return 0;
}
