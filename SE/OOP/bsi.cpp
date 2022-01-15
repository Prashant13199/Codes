#include<iostream>
using namespace std;

class first
{
 int a[100],b[100],c[100],i,n,j,ey,min;
 public:
 int temp;
 void scan();
 void bubble();
 void selection();
 void insertion();
};
 void first::scan()
 {
  cout<<"Enter size of an array";
  cin>>n;
  for(i=0;i<n;i++)
   {
    cin>>a[i];
   }
  for(i=0;i<n;i++)
   {
    c[i]=b[i]=a[i];
   }
  for(i=0;i<n;i++)
   {
    cout<<a[i];
   }
 }
void first::bubble()
 {
  for(i=0;i<n-1;i++)
   {
    for(j=0;j<n-i-1;j++)
     {
      if(a[j]>a[j+1])
       {
        int temp;
        temp=a[j];
        a[j]=a[j+1];
        a[j+1]=temp;
       }
     }
   }
  cout<<"List of sorted elements:";
  for(int i=0;i<n;i++)
   {
    cout<<"\n"<<a[i];
   }
 }
void first::selection()
 {
  for(i=0;i<n-1;i++)
   {
    min=i;
    for(j=i+1;j<n;j++)
     {
      if(a[j]<a[min])
       {
        min=j;
       }
     }
     temp=a[i];
     a[i]=a[min];
     a[min]=temp;
   }
    cout<<"List of sorted elements:";
  for(int i=0;i<n;i++)
   {
    cout<<"\n"<<a[i];
   }
 }
void first::insertion()
 {
  for(i=1;i<n;i++)
   {
    ey=a[i];
    j=i-1;
    while(j>=0&&a[j]>ey)
    {
     a[j+1]=a[j];
     j--;
    }
   a[j+1]=ey;
   }
  cout<<"List of sorted elements:";
  for(int i=0;i<n;i++)
   {
    cout<<"\n"<<a[i];
   }
}
   
int main()
 {
  int z;
  first obj;
  obj.scan();
  cout<<"Enter 1 for using bubble\n"<<"Enter 2 for using selection\n"<<"Enter 3 for using insertion";
  cin>>z;
  switch(z)
  {
  case 1:obj.bubble();
  case 2:obj.selection();break;
  case 3:obj.insertion();break;
  default:cout<<"Wrong choice";
  }
  return 0;
 }
 

 
 
