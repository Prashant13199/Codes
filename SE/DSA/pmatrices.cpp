#include<iostream>
using namespace std;

class matrix
{
public:
int a[20][20],b[20][20],c[20][20],d[20][20],i,j,m,k,x,y,t[20][20];
void order()
{
cout<<"Enter the order of the matrix:";
cin>>m;
}

void getdata()
{
cout<<"Enter the elements of the matrix 1:";
for(i=0;i<m;i++)
 {
  for(j=0;j<m;j++)
  {
   cin>>a[i][j];
  }
 }
}

void getdata2()
{
 cout<<"Enter the elements of the matrix 2:";
 for(i=0;i<m;i++)
  {
   for(j=0;j<m;j++)
   {
    cin>>b[i][j];
   }
  }
}

void addition()
{
 for(i=0;i<m;i++)
 {
  for(j=0;j<m;j++)
  {
   c[i][j]=a[i][j]+b[i][j];
  }
 }cout<<"The result of addition is:"<<"\n";
for(i=0;i<m;i++)
{
for(j=0;j<m;j++)
{
cout<<c[i][j]<<"\t";
}
cout<<"\n";
}
}

void subtraction()
{
for(i=0;i<m;i++)
{
for(j=0;j<m;j++)
{
c[i][j]=a[i][j]-b[i][j];
}
}

cout<<"The result of subtraction is:"<<"\n";
for(i=0;i<m;i++)
{
 for(j=0;j<m;j++)
 {
  cout<<c[i][j]<<"\t";
 }
  cout<<"\n";
}
}

void multiplication()
{
for(i=0;i<m;i++)
 {
  for(j=0;j<m;j++)
   {
    d[i][j]=0;
     for(k=0;k<m;k++)
      {
       d[i][j]=(a[i][k]*b[k][j])+d[i][j];
      }
   }
  }cout<<"The result of multiplication is:"<<"\n";
for(i=0;i<m;i++)
 {
  for(j=0;j<m;j++)
   {
  cout<<d[i][j]<<"\t";
   }
  cout<<"\n";
  }
}
void transpose()
{
cout<<"The result of transpose is:"<<"\n";
   for(x=0;x<m;x++)
    {
     for(y=0;y<m;y++)
      {
       t[y][x]=a[i][j];
      }
    } 
 
  for(i=0;i<m;i++)
  {
   for(j=0;j<m;j++)
    {
     cout<<t[y][x]<<"\t";
    }
       cout<<"\n";
}  }  
};
int main()
{
 matrix obj;
 obj.order();
 obj.getdata();
 obj.getdata2();
 obj.addition();
 obj.subtraction();
 obj.multiplication();
 obj.transpose();
 return 0;
}

