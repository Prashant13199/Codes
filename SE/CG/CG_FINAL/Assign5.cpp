#include<iostream>
#include<graphics.h>
#include<math.h>
#include<iomanip>
using namespace std;


class pixel
{
 public:

 int ROUND(float a)
 {
    int b;
    b=a;
    return b;
  }
 void setpixel(float x,float y)
  {
    putpixel(ROUND(x),ROUND(y),BLUE);
  }
};

class draw:public pixel
{
public:
void draw1(float xa,float ya,float xb,float yb)
 {
  int dx=xb-xa,dy=yb-ya,steps,k;
  float xIncrement,yIncrement,x=xa,y=ya;
  if(abs(dx)>abs(dy))
   steps=abs(dx);
  else
   steps=abs(dy);
  xIncrement=dx/(float)steps;
  yIncrement=dy/(float)steps;

  putpixel(ROUND(x),ROUND(y),WHITE);


 for(k=0;k<steps;k++)
{ x+=xIncrement;
 y+=yIncrement;
 putpixel(ROUND(x),ROUND(y),WHITE);
 }
 }
 void dr(int ,int ,int ,int);
 void bres(int ,int ,int);


};

void draw::dr(int x,int y,int x1,int y1)
{
  putpixel(x+x1 ,y+y1, WHITE);
  putpixel(x+x1 ,y-y1, WHITE);
  putpixel(x-x1 ,y+y1, WHITE);
  putpixel(x-x1 ,y-y1, WHITE);
  putpixel(x+y1 ,y+x1, WHITE);
  putpixel(x+y1 ,y-x1, WHITE);
  putpixel(x-y1 ,y+x1, WHITE);
  putpixel(x-y1 ,y-x1, WHITE);
}

void draw::bres(int x,int y,int r)
{
  int x1,y1;
  float d;
  d=3-2*r;
  x1=0;
  y1=r;
  while(x1<=y1)
  {
     if(d<0)
      d+=(4*x1)+6;
     else
     {
       d+=4*(x1-y1)+10;
       y1--;
       }
     x1++;
     dr(x,y,x1,y1);
   }
}

int main()
{
  draw d;
  int gd=DETECT,gm;
  initgraph(&gd,&gm,NULL);
  d.draw1(56.7,125,100,50);
  d.draw1(143.3,125,100,50);
  d.draw1(56.7,125,143.3,125);
  d.bres(100,100,50);
  d.bres(100,100,25);
  getch();
  closegraph();
  return 0;
}
