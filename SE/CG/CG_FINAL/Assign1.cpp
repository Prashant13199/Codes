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
   void draw1(int ,int ,int ,int ,int);
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
int sign(int x)
{
  if(x>0)
   return 1;
  else if(x<0)
   return -1;
  else
   return 0;
}
void draw::draw1(int xa,int ya,int xb,int yb,int inter)
{
  int dx,dy,i,s1,s2,e,x,y;
  x=xa;
  y=ya;
  dx=abs(xb-xa);
  dy=abs(yb-ya);
  s1=sign(xb-xa);
  s2=sign(yb-ya);
  if(dy>dx)
  {
    int temp;
    temp=dx;
    dx=dy;
    dy=temp;
    inter=1;
  }
 else
   inter=0;
 e=2*dy-dx;
 for(i=0;i<dx;i++)
 {
   setpixel(x,y);
   while(e>0)
    {
      if(inter==1)
       x+=s1;
      else
       y+=s2;
      e-=2*dx;
     }
   if(inter==1)
    y+=s2;
   else
    x+=s1;
   e+=2*dy;
  }
  
}


int main()
{
  int ch,xa,ya,xb,yb;
  int gd=DETECT,gm;
  draw d;
  do
   {
     cout<<"\n1.DDA method\n2.bresenham\n3.exit";
     cout<<"\nEnter your choice: ";
     cin>>ch;
     switch(ch)
      {
        case 1:cout<<"\nEnter starting and ending points of the line. ";
               cin>>xa>>ya>>xb>>yb;
               initgraph(&gd,&gm,NULL);
               d.draw1(xa,ya,xb,yb);
               getch();
               closegraph();
               break;
        case 2:cout<<"\nEnter starting and ending points of the line. ";
               cin>>xa>>ya>>xb>>yb;
               initgraph(&gd,&gm,NULL);
               d.draw1(xa,ya,xb,yb,0);
               getch();
               closegraph();
               break;
        case 3:return 0;
               break;
        default:cout<<"\nIncorrect choice.";
       }
    }
  while(ch!=3);
}
