#include<iostream>
#include<graphics.h>
#include<math.h>
using namespace std;
# define ROUND(a) ((int)(a+0.5))

class pixel
{
  public:
   void setpixel(float x,float y)
    {
       putpixel(ROUND(x),ROUND(y),WHITE);
     }
};

class draw:public pixel
{
  public:
   void draw1(int ,int, int ,int);
};

void draw::draw1(int xa,int ya,int xb,int yb)
{
 int dx,dy,steps,i;
 float xinc,yinc,x,y;
 dx=xb-xa;
 dy=yb-ya;
 x=xa;
 y=ya;
 if(abs(dx)>abs(dy))
  {steps=abs(dx);}
 else
  {steps=abs(dy);}
 xinc=dx/(float)steps;
 yinc=dy/(float)steps;
 setpixel(x,y);
 for(i=0;i<steps;i++)
  {
    x+=xinc;
    y+=yinc;
    setpixel(x,y);
   }
}
int main()
{
  draw l;
  int gd=DETECT,gm;
  initgraph(&gd,&gm,NULL);
  l.draw1(100,100,300,100);
  l.draw1(300,100,300,200);
  l.draw1(300,200,100,200);
  l.draw1(100,100,100,200);
  l.draw1(100,150,200,100);
  l.draw1(200,100,300,150);
  l.draw1(300,150,200,200);
  l.draw1(200,200,100,150);
  l.draw1(150,125,250,125);
  l.draw1(250,125,250,175);
  l.draw1(250,175,150,175);
  l.draw1(150,175,150,125);
  getch();
  closegraph();
  return 0;
}
