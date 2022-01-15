#include<iostream>
#include<graphics.h>
#include<math.h>
using namespace std;

class fractal
{
  public:
   void koch(int,int,int,int,int);
};

void fractal::koch(int n,int x1,int y1,int x5,int y5)
{
 int deltax,deltay,x2,y2,x3,y3,x4,y4;
 if(n==0)
 line(x1,y1,x5,y5);
else
 {
  deltax=x5-x1;
  deltay=y5-y1;
  x2=x1+deltax/3;
  y2=y1+deltay/3;
  x4=x1+(2*(deltax/3));
  y4=y1+(2*(deltay/3));
  x3=(int)(0.5*(x1+x5)+sqrt(3)*(y1-y5)/6);
  y3=(int)(0.5*(y1+y5)+sqrt(3)*(x5-x1)/6);
  koch(n-1,x1,y1,x2,y2);
  koch(n-1,x2,y2,x3,y3);
  koch(n-1,x3,y3,x4,y4);
  koch(n-1,x4,y4,x5,y5);
  
 }
}

int main()
{
  int n,x1,y1,x5,y5;
  fractal f;
  int gd=DETECT,gm;
  cout<<"\nEnter starting and ending co-ordinates of the line to draw koch curve: ";
  cin>>x1>>y1>>x5>>y5;
  cout<<"\nEnter no. of iterations: ";
  cin>>n;
  initgraph(&gd,&gm,NULL);
  f.koch(n,x5,y5,x1,y1);
  getch();
  closegraph();
  return 0;
}
