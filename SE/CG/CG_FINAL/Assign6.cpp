#include<iostream>
#include<graphics.h>
#include<math.h>
using namespace std;
# define ROUND(a) ((int)(a+0.5))
class pixel
{
 public:
  void setpixel(int x,int y)
   {
      putpixel(ROUND(x),ROUND(y),WHITE);
    }
};
 
class lines:public pixel
{
 int xa,ya,xb,yb;
  public:
  void accept();
  void solid();
  void dotted();
  void dash();
  void dot_dash();
  void thick(int);
};
void lines::accept()
{
  cout<<"\nEnter starting and ending co-ordinates of the line";
  cin>>xa>>ya>>xb>>yb;
}
void lines::solid()
{
 int dx,dy,steps,i;
 float xinc,yinc,x,y;
 x=xa;
 y=ya;
 dx=abs(xb-xa);
 dy=abs(yb-ya);
 if(dx>dy)
  {steps=dx;}
 else
  {steps=dy;}
 setpixel(x,y);
 xinc=dx/(float)steps;
 yinc=dy/(float)steps;
 for(i=0;i<steps;i++)
  {
    x+=xinc;
    y+=yinc;
    setpixel(x,y);
  }
}
void lines::dotted()
{
 int dx,dy,steps,i;
 float xinc,yinc,x,y;
 x=xa;
 y=ya;
 dx=abs(xb-xa);
 dy=abs(yb-ya);
 if(dx>dy)
  {steps=dx;}
 else
  {steps=dy;}
 setpixel(x,y);
 xinc=dx/(float)steps;
 yinc=dy/(float)steps;
 for(i=0;i<steps;i++)
  {
    x+=xinc;
    y+=yinc;
    if(i%2==0)
    continue;
    else
    setpixel(x,y);
  }
}
void lines::dash()
{
 int dx,dy,steps,i,cnt;
 cnt=0;
 float xinc,yinc,x,y;
 x=xa;
 y=ya;
 dx=abs(xb-xa);
 dy=abs(yb-ya);
 if(dx>dy)
  {steps=dx;}
 else
  {steps=dy;}
 setpixel(x,y);
 xinc=dx/(float)steps;
 yinc=dy/(float)steps;
 for(i=0;i<steps;i++)
  {
    x+=xinc;
    y+=yinc;
    cnt++;
    if(cnt<6)
    setpixel(x,y);
    else if(cnt==10)
     cnt=0;
  }
}

void lines::dot_dash()
{
 int dx,dy,steps,i,cnt;
 cnt=0;
 float xinc,yinc,x,y;
 x=xa;
 y=ya;
 dx=abs(xb-xa);
 dy=abs(yb-ya);
 if(dx>dy)
  {steps=dx;}
 else
  {steps=dy;}
 setpixel(x,y);
 xinc=dx/(float)steps;
 yinc=dy/(float)steps;
 for(i=0;i<steps;i++)
  {
    x+=xinc;
    y+=yinc;
    cnt++;
    if(cnt<=4)
    setpixel(x,y);
    else if(cnt>4 && cnt<7)
     continue;
    else if(cnt==7)
    setpixel(x,y);
    else if(cnt==10)
      cnt=0;
  }
}

void lines::thick(int w)
{
  int m=(xb-xa)/(yb-ya),tx,ty;
  if(m<1)
   {
      ty=(w-1)*sqrt(pow((xb-xa),2)+pow((yb-ya),2))/(2*fabs(xb-xa));
      for(int i=0;i<ty;i++)
      {
        ya=ya-i;
        yb=yb-i;
        solid();
        ya=ya+i;
        yb=yb+i;
        ya=ya+i;
        yb=yb+i;
        solid();
       }
    }
  else
   {
      tx=(w-1)*sqrt(pow((xb-xa),2)+pow((yb-ya),2))/(2*fabs(yb-ya));
      for(int i=0;i<tx;i++)
      {
        xa=xa-i;
        xb=xb-i;
        solid();
        xa=xa+i;
        xb=xb+i;
        xa=xa+i;
        xb=xb+i;
        solid();
       }


    }
}

int main()
{
  int ch,w;
  lines  l;
  int gd=DETECT,gm;
  do
   {
     cout<<"\n1.Solid line\n2.Dotted line\n3.Dashed line\n4.dot dash line\n5.thick line\n6.Exit";
     cout<<"\nEnter your choice: ";
     cin>>ch;
     switch(ch)
      {
        case 1:l.accept();
                initgraph(&gd,&gm,NULL);
                l.solid();
                getch();
                closegraph();
                break;
        case 2: l.accept();
                initgraph(&gd,&gm,NULL);
                l.dotted();
                getch();
                closegraph();
                break;
        case 3: l.accept();
                initgraph(&gd,&gm,NULL);
                l.dash();
                getch();
                closegraph();
                break;
        case 4: l.accept();
                initgraph(&gd,&gm,NULL);
                l.dot_dash();
                getch();
                closegraph();
                break;
        case 5: l.accept();
                cout<<"\nEnter thickness of line. ";
                cin>>w;
                initgraph(&gd,&gm,NULL);
                l.thick(w);
                getch();
                closegraph();
                break;
        case 6:return 0;
               break;
        default:
                cout<<"\nIcorrect choice.";
              
       }
   }
  while(ch!=6);
}
