#include<iostream>
#include<graphics.h>
#include<math.h>
using namespace std;


void print(float arr[][3])
{
for(int i=0;i<3;i++)
 {
  for(int j=0;j<3;j++)
    cout<<arr[i][j]<<" ";
     cout<<endl;
  }
}
class transform
{
 float A[3][3],B[3][3],C[3][3];
 public:
 void accept();
 void operator *();
 void operator ++();
 void operator --();
 void multi();
 void draw();
 void draw1();
};

void transform::accept()
{
 int i,j;
 for(i=0,j=0;j<3;j++)
  {
    cout<<"\nEnter coordinates(x,y) of the polygon(triangle)";
    cin>>A[i][j];
    i++;
    cin>>A[i][j];
    i++;
    A[i][j]=1;
    i=0;
  }

}

void transform::operator--()
{
  int i,j;
  int A;
  cout<<"\nEnter angle by which you want to rotate: ";
  cin>>A;
  for(i=0;i<3;i++)
   {
     for(j=0;j<3;j++)
      {
        if(i==j)
        B[i][j]=1;
        else
        B[i][j]=0;
      }
   }
  B[0][0]=cos(A);
  B[0][1]=sin(A);
  B[1][0]=-sin(A);
  B[1][1]=cos(A);
}

void transform::operator++()
{
  int i,j;
  int tx,ty;
  cout<<"\nEnter translation factors (tx,ty): ";
  cin>>tx>>ty;
  for(i=0;i<3;i++)
   {
     for(j=0;j<3;j++)
      {
        if(i==j)
        B[i][j]=1;
        else
        B[i][j]=0;
      }
   }
  B[0][2]=tx;
  B[1][2]=ty;
  
}
void transform::operator*()
{
 int i,j;
 cout<<"\nEnter scaling factors(sx,sy,1)";
  for(i=0;i<3;i++)
   {
     for(j=0;j<3;j++)
      {
        if(i==j)
        cin>>B[i][j];
        else
        B[i][j]=0;
      }
   }
}

void transform::multi()
{
int i,j,k,z;for(int i=0;i<3;i++)for(int j=0;j<3;j++)C[i][j]=0;
for(i=0;i<3;i++)
 {
   for(j=0;j<3;j++)
    {
      for(k=0;k<3;k++)
       {
         C[i][j]+=B[i][k]*A[k][j];
       }
    }
 }
 print(A);cout<<endl;
 print(B);cout<<endl;
 print(C);cout<<endl;
}

void transform::draw()
{
 
 
 line(C[0][0],C[1][0],C[0][1],C[1][1]);
 line(C[0][2],C[1][2],C[0][0],C[1][0]);
 line(C[0][1],C[1][1],C[0][2],C[1][2]);
 
}
void transform::draw1()
{
 
 
 line(A[0][0],A[1][0],A[0][1],A[1][1]);
 line(A[0][2],A[1][2],A[0][0],A[1][0]);
 line(A[0][1],A[1][1],A[0][2],A[1][2]);
 
}

int main()
{
 transform t;
 int ch;
 int gdriver=DETECT,gmode;
 do
 {
  cout<<"\n1.Scaling\n2.Translation\n3.Rotation\n4.Exit";
  cout<<"\nEnter your choice";
  cin>>ch;
  
  switch(ch)
   {
     case 1:t.accept();
            *t;
            t.multi();
            initgraph(&gdriver,&gmode,NULL);
            t.draw();
            t.draw1();
            getch();
            closegraph();
            break;
     case 2:t.accept();
            ++t;
            t.multi();
            initgraph(&gdriver,&gmode,NULL);
            t.draw();
            t.draw1();
            getch();
            closegraph();
            break;
     case 3:t.accept();
            --t;
            t.multi();
            initgraph(&gdriver,&gmode,NULL);
            t.draw();
            t.draw1();
            getch();
            closegraph();
            break;
     case 4:return 0;
            break;
     default:cout<<"\n Incorrect choice.";
   }
   

 }
 
 while(ch!=4);
}
