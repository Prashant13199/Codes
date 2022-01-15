#include<iostream>
using namespace std;

class ABC
 {
  int i,j,n;
  int a[100],b[100];
  public:
  
 
 
void getdata()
 {
  cout<<"\nEnter the number of students:";
  cin>>n;
  cout<<"\nEnter the roll numbers:";
  for(i=0;i<n;i++)
   {
    cin>>a[i];
   }
 }

void showdata()
 {
  for(i=0;i<n;i++)
   {
    cout<<"\nEntered roll numbers are:"<<a[i];
   }
 }

void search()
 {
  int k;
  int flag=0;
  cout<<"\nEnter the roll number to search";
  cin>>k;
  
  for(i=0;i<n;i++)
   {
    if(a[i]==k)
    {
     flag=1;break;
    }
   }
   if(flag==1)
    {
     cout<<"\nAttended";
     cout<<"\nPostition is:"<<i+1;
    }
   else
    {
     cout<<"\n Not Attended";
    }
   
 }
 
void search2()
 {
  int key,last;
  cout<<"\nEnter the roll number to search:";
  cin>>key;
  last=a[n-1];
  a[n-1]=key;
  int i=0;
  while(a[i]!=key)
  { 
   i++;
  }
  
   a[n-1]=last;
  
 if(i<n-1||a[n-1]==key)
  {
   cout<<"\nAttended";
  }
 else
  {
   cout<<"\nNot Attended";
  }
 }

void search3()
 {
 int key,mid,low=0,flag,high;
  cout<<"Enter the number of students:";
  cin>>n;
  high=n;
  cout<<"Enter the roll numbers in sorted form:";
  for(i=0;i<n;i++)
   {
    cin>>b[i];
   }
  cout<<"Enter the roll number to search:";
  cin>>key;
  while(low<=high)
   {
    mid=(low+high)/2;
    if(b[mid]==key)
     {
      cout<<"roll number found";
      flag=1;
      break;
      }
      else if(a[mid]>key)
       {
        high=mid-1;
        }
       else if(a[mid]<key)
        {
         low=mid+1;
        }
       if(flag==0)
        {
         cout<<"Roll number not found";
      }
      }
      }
   
   
        
     
  
  
};

int main()
 {
  int w;
  ABC s;
  cout<<"\nEnter 1 for linear search";
  cout<<"\nEnter 2 for sequential search";
  cout<<"\nEnter 3 for binary search";
  cin>>w;
  switch(w)
  {
  case 1:s.getdata();
         s.showdata();
         s.search();
         break;
  case 2:
         s.getdata();
         s.showdata();
         s.search2();
         break;
  case 3:
         s.search3();break;
  
  }
  return 0;
 }
    
  
  
